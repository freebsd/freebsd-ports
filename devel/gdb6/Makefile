# ex:ts=8
# Ports collection makefile for:	GDB 5.1
# Date created:				30 March 2001
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $FreeBSD$
#

SNAPDATE=	2004-04-13
SNAPVER=	${SNAPDATE:S/-//g}

PORTNAME=	gdb
PORTVERSION=	6
PORTREVISION=	${SNAPVER}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	gdb/snapshots/current
DISTNAME=	gdb+dejagnu-weekly-${SNAPVER}

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	GNU GDB 6

WRKSRC=		${WRKDIR}/${DISTNAME:S/-weekly//}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=6
CFLAGS+=	-DRL_NO_COMPAT

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64" || ${ARCH} == "ia64"
PLIST_SUB+=	NO_NATIVE_GDB=""
post-install:
	cd ${PREFIX}/bin ; ${LN} -sf gdb${PORTVERSION} gdb
.else
PLIST_SUB+=	NO_NATIVE_GDB="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/$$/ [FreeBSD]/' ${WRKSRC}/gdb/version.in

do-patch: post-patch
	@${ECHO} 'FreeBSD-specific patches disabled for now, until upgraded.'
	@${REINPLACE_CMD} -e 's/^READLINE/#READLINE/' \
		-e 's/^readline/#readline/' \
		${WRKSRC}/gdb/Makefile.in
	echo 'READLINE = -lreadline' >> ${WRKSRC}/gdb/Makefile.in

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect readline sim tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${PREFIX}/bin/${PORTNAME}${PORTVERSION:S/.//g}

cklatest:
	ncftpls \
	    ftp://sources.redhat.com/pub/${MASTER_SITE_SUBDIR}/  \
	    | ${GREP} gdb+dejagnu-weekly

.include <bsd.port.post.mk>
