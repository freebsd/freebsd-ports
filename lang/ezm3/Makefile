# New ports collection makefile for:	ezm3
# Date created:		1 Jan 2002
# Whom:			John Polstra <jdp@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ezm3
PORTVERSION=	1.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_FREEBSD_ORG}
MASTER_SITE_SUBDIR=development/CVSup/ezm3
DISTFILES=	${BOOTSTRAP} \
		ezm3-${PORTVERSION}-src.tar.bz2

MAINTAINER=	jdp@FreeBSD.org

DIST_SUBDIR=	ezm3
INSTALL_TARGET=	all
MAKE_ARGS+=	M3OPTIONS="-DBUILD_ALL -DSHIP_ALL"
MAN1=		m3bundle.1
PLIST_SUB+=	TARGET=${TARGET} TARGETDIR=${TARGETDIR} WORDSIZE=${WORDSIZE}
SCRIPTS_ENV+=	TARGET=${TARGET}
USE_BZIP2=	yes
USE_GMAKE=	yes

PROGS=		bin/m3build \
		bin/m3bundle \
		bin/m3ship \
		lib/m3/${TARGET}/m3cgc1
BOOTSTRAP=	ezm3-${PORTVERSION}-${TARGET}-boot.tar.bz2

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
TARGET=		FreeBSD2
TARGETDIR=	freebsd-2
WORDSIZE=	32
.elif ${ARCH} == "i386"
.if ${OSVERSION} < 400011
TARGET=		FreeBSD3
TARGETDIR=	freebsd-3
.else
TARGET=		FreeBSD4
TARGETDIR=	freebsd-4
.endif
WORDSIZE=	32
.elif ${ARCH} == "alpha"
.if ${OSVERSION} < 400011
BROKEN=		Not supported on older versions of FreeBSD/Alpha
.endif
TARGET=		FBSD_ALPHA
TARGETDIR=	fbsd-alpha
WORDSIZE=	64
.endif

.if empty(TARGET)
pre-fetch:
	@${ECHO_MSG} "Cannot determine M3 target for this architecture"
	@${FALSE}
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
	@for i in ${PROGS}; do strip ${PREFIX}/$$i; done
	@${MKDIR} ${PREFIX}/share/ezm3
	@${INSTALL_DATA} ${WRKSRC}/src/COPYRIGHT ${PREFIX}/share/ezm3

.include <bsd.port.post.mk>
