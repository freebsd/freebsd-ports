# New ports collection makefile for:	VJE-Delta 3.0 + update
# Date created:		29 January 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	vje
PORTVERSION=	3.0
PORTREVISION=	3
CATEGORIES=	japanese
MASTER_SITES=	${CD_MOUNTPTS:S,^,file:,:S,$,/freebsd/,} \
		${CD_MOUNTPTS:S,^,file:,:S,$,/source/delta/:source,} \
		${MASTER_SITE_LOCAL:S/$/:update/}
MASTER_SITE_SUBDIR=	knu/:update
DISTFILES=	${MAINDIST} \
		delta.tgz:source \
		vje-delta-3.0-ELF-update-2002.05.31.tgz:update \
		vje-delta-3.0-source-update-2002.05.31.tgz:update
DIST_SUBDIR=	vje30

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Modern intelligent Japanese input engine (purchase version)

LIB_DEPENDS=	c.3:${PORTSDIR}/misc/compat3x
#RUN_DEPENDS=	${LOCALBASE}/share/java/classes/jfc-1.1.1/swing.jar:${PORTSDIR}/java/jfc

RESTRICTED=	"You must purchase a licensed copy from VACS Corporation."
NO_CDROM=	"You must purchase a licensed copy from VACS Corporation."
NO_PACKAGE=	"You must purchase a licensed copy from VACS Corporation."

ONLY_FOR_ARCHS=	i386

USE_RC_SUBR=	yes

USE_XLIB=	yes
USE_REINPLACE=	yes

PLIST_SUB=	BINSTUFF="${BINSTUFF}"

WRKSRC=		${WRKDIR}/usr/local
PATCH_WRKSRC=	${WRKDIR}
BUILD_WRKSRC=	${WRKDIR}/delta/newFrontend
MAKEFILE=	Makefile.FreeBSD

.include <bsd.port.pre.mk>

MAINDIST=	${PORTNAME}-delta-${PORTVERSION}-ELF.tgz

BINSTUFF=	vje	\
		vjed	\
		vadd	\
		vdel	\
		vdispd	\
		vmaked	\
		vpen	\
		vpu	\
		vjekill	\
		vpr	\
		vprc	\
		vjeacc

pre-fetch:
	@check () { for m; do [ -d $$m/freebsd ] && return 0; done; return 1; }; check ${CD_MOUNTPTS} || ( \
	${ECHO} "*****************************************************************";	\
	${ECHO} "To install VJE-Delta 3.0, make sure your purchased CD-ROM is";		\
	${ECHO} "mounted on at ${CD_MOUNTPTS} or any arbitrary mountpoint that";	\
	${ECHO} "can be specified using the CD_MOUNTPTS variable.";	\
	${ECHO} "";									\
	${ECHO} "e.g.";									\
	${ECHO} "	mount /dev/cd0c /mnt/cdrom";					\
	${ECHO} "	make CD_MOUNTPTS=/mnt/cdrom install";				\
	${ECHO} "*****************************************************************";	\
	${FALSE}									\
	)

post-extract:
	@${RM} ${DISTDIR}/${DIST_SUBDIR}/${MAINDIST} ${WRKDIR}/vje

post-patch:
	@cd ${WRKSRC}/vje30/bin && ${RM} swingall.jar
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' -e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		${FILESDIR}/vje.sh > ${WRKSRC}/etc/rc.d/vje.sh
	@${REINPLACE_CMD} 's,/usr/X11R6,${X11BASE},g' ${BUILD_WRKSRC}/${MAKEFILE}
.if defined(NOPORTDOCS)
	@cd ${WRKSRC}/vje30 && ${RM} -rf doc README FAQ REQUEST
.endif

post-build:
	@${CP} ${BUILD_WRKSRC}/vje ${WRKSRC}/vje30/bin/

do-install:
	@${TAR} -C ${WRKSRC} -cf - . | ${TAR} -C ${PREFIX} -xf -
.for f in ${BINSTUFF}
	@${LN} -fs ${PREFIX}/vje30/bin/$f ${PREFIX}/bin/$f
.endfor
	@${CHMOD} a+x ${PREFIX}/etc/rc.d/vje.sh
	@${CHMOD} a+w ${PREFIX}/vje30/dic/vjed95m.dic
	@[ X${PREFIX} = X"/usr/local" ] || (${LN} -s ${PREFIX}/vje30 /usr/local/; ${LN} -s ${PREFIX}/etc/vje30 /usr/local/etc/)
	@${CP} ${WRKDIR}/vjed.bin /tmp/
	@${ECHO_CMD} '' | ${WRKDIR}/vjesetup
	@${RM} /tmp/vjed.bin
	@${CP} -Pp /etc/services /etc/services.bak
	@${GREP} -qw '^vjed' /etc/services || ${ECHO_CMD} "vjed		11493/tcp		# VJE-Delta Server" >> /etc/services

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
