# New ports collection makefile for:	ezm3
# Date created:		1 Jan 2002
# Whom:			John Polstra <jdp@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ezm3
PORTVERSION=	1.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_FREEBSD_ORG}
MASTER_SITE_SUBDIR=development/CVSup/ezm3
DISTFILES=	${BOOTSTRAP} \
		ezm3-${PORTVERSION}-src.tar.bz2

MAINTAINER=	jdp@FreeBSD.org
COMMENT=	Easier, more portable Modula-3 distribution for building CVSup

DIST_SUBDIR=	ezm3
INSTALL_TARGET=	all
MAKE_ARGS+=	M3OPTIONS="-DBUILD_ALL -DSHIP_ALL"
MAN1=		m3bundle.1
PLIST_SUB+=	ARCH=${ARCH} TARGET=${TARGET} WORDSIZE=${WORDSIZE} \
		ENDIANESS=${ENDIANESS}
SCRIPTS_ENV+=	TARGET=${TARGET}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

PROGS=		bin/m3build \
		bin/m3bundle \
		bin/m3ship \
		lib/m3/${TARGET}/m3cgc1

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	alpha i386 sparc64

.if ${OSVERSION} < 410000
BROKEN=		Not supported on versions earlier than 4.1-RELEASE
.endif

.if ${ARCH} == "alpha"
TARGET=		FBSD_ALPHA
WORDSIZE=	64
ENDIANESS=	le
BOOTSTRAP=	ezm3-${PORTVERSION}a-${TARGET}-boot.tar.bz2
.elif ${ARCH} == "i386"
TARGET=		FreeBSD4
WORDSIZE=	32
ENDIANESS=	le
BOOTSTRAP=	ezm3-${PORTVERSION}-${TARGET}-boot.tar.bz2
.elif ${ARCH} == "sparc64"
TARGET=		FBSD_SPARC64
WORDSIZE=	64
ENDIANESS=	be
BOOTSTRAP=	ezm3-${PORTVERSION}-${TARGET}-boot.tar.bz2
.endif

post-patch:
.if ${ARCH} == "sparc64" && ${OSVERSION} < 502107
	@${REINPLACE_CMD} -E -e 's|(^.*time_t.*=.*)int64_t;|\1int32_t;|' \
		${WRKSRC}/libs/m3core/src/unix/freebsd-4.sparc64/Utypes.i3
.endif

do-build:
	@${ECHO_MSG} "This port does everything in the install step."
	@${ECHO_MSG} "The build step is a no-op."

pre-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/check_conflicts

do-install:
	@${RM} -rf ${WRKSRC}/${TARGET}
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
	@for i in ${PROGS}; do ${STRIP_CMD} ${PREFIX}/$$i; done
	@${MKDIR} ${PREFIX}/share/ezm3
	@${INSTALL_DATA} ${WRKSRC}/src/COPYRIGHT ${PREFIX}/share/ezm3

.include <bsd.port.post.mk>
