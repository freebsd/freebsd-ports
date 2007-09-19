# New ports collection makefile for:	oss
# Date created:		2007-06-14
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	oss
DISTVERSION=	4.0-build1006
PORTREVISION=	1
CATEGORIES=	audio kld
MASTER_SITES=	http://developer.opensound.com/sources/stable/
DISTNAME=	${PORTNAME}-v${DISTVERSION}-src-cddl

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Open Sound System

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

USE_BZIP2=	yes
ALL_TARGET=	all install
USE_LDCONFIG=	yes
USE_GNOME=	gtk20
USE_RC_SUBR=	oss
WRKSRC=		${WRKDIR}/build
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
SUB_FILES=	pkg-install pkg-message
ONLY_FOR_ARCHS=	amd64 i386

MAN1=		ossinfo.1 ossmix.1 ossplay.1 ossrecord.1 osstest.1 ossxmix.1
MAN8=		ossctl.8 ossdevlinks.8 savemixer.8 ossdetect.8

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source to be installed
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BROKEN=		Does not compile on 5.x.
.endif

pre-patch:
	${REINPLACE_CMD} -e 's|"/usr/include/stdarg.h"|<${ARCH}/include/stdarg.h>|g' \
		-e "s|<i386/include/intr_machdep.h>|<${ARCH}/include/intr_machdep.h>|g" \
		${WRKDIR}/${DISTNAME}/setup/FreeBSD/oss/build/module.inc \
		${WRKDIR}/${DISTNAME}/setup/FreeBSD/oss/build/osscore.c
	${REINPLACE_CMD} -e "s|mkdir|mkdir -p|" ${WRKDIR}/${DISTNAME}/setup/FreeBSD/build.sh
	${FIND} ${WRKDIR}/${DISTNAME} -type f -name '*.[hc]' -or -name '*.man' | \
		${XARGS} ${REINPLACE_CMD} \
		-e 's|/usr/|${PREFIX}/|g' \
		-e 's|/etc/oss|${PREFIX}/etc/oss|g'

post-patch:
	${FIND} ${WRKDIR} -name soundon -or -name soundoff -or -name build.sh | ${XARGS} ${REINPLACE_CMD} \
		-e 's|%%PREFIX%%|${PREFIX}|g'

do-configure:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && ${WRKDIR}/${DISTNAME}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/prototype/usr/bin/* ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/prototype/usr//sbin/savemixer ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/prototype/usr/sbin/ossdevlinks ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/prototype/usr/sbin/ossdetect ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/prototype/usr/sbin/ossctl ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/prototype/usr/sbin/soundon ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/prototype/usr/sbin/soundoff ${PREFIX}/sbin
	#${INSTALL_PROGRAM} ${WRKSRC}/prototype/usr/lib/oss/lib/libOSSlib.so ${PREFIX}/lib
	@# oss.conf does not contain any user-configurable data; it's ok to overwrite it.
	${INSTALL_DATA} ${WRKSRC}/prototype/etc/oss.conf ${PREFIX}/etc/oss.conf
	${MKDIR} ${PREFIX}/include/sys
	${INSTALL_DATA} ${WRKSRC}/prototype/usr/lib/oss/include/sys/soundcard.h ${PREFIX}/include/sys
	#${INSTALL_DATA} ${WRKSRC}/prototype/usr/lib/oss/include/midiparser.h ${PREFIX}/include
	${MKDIR} ${PREFIX}/lib/oss
	${MKDIR} ${PREFIX}/lib/oss/logs
	${MKDIR} ${PREFIX}/lib/oss/etc
	${INSTALL_DATA} ${WRKSRC}/prototype/usr/lib/oss/etc/devices.list ${PREFIX}/lib/oss/etc
	${INSTALL_DATA} ${WRKSRC}/prototype/usr/lib/oss/version.dat ${PREFIX}/lib/oss
	${INSTALL_DATA} ${WRKSRC}/prototype/usr/lib/oss/sysfiles.list ${PREFIX}/lib/oss
	${MKDIR} ${PREFIX}/lib/oss/modules
	${INSTALL_DATA} ${WRKSRC}/prototype/usr/lib/oss/modules/* ${PREFIX}/lib/oss/modules
	${INSTALL_MAN} ${WRKSRC}/prototype/usr/man/man8/* ${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/prototype/usr/man/man1/* ${PREFIX}/man/man1/
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
