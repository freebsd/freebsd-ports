# New ports collection makefile for:	pm3-base
# Date created:		6 Feb 2000
# Whom:			John Polstra <jdp@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pm3-base
PORTVERSION=	1.1.15
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=jdp/pm3
DISTFILES=	${BOOTSTRAP} \
		pm3-${PORTVERSION}-src.tar.bz2

MAINTAINER=	jdp@FreeBSD.org
COMMENT=	Compiler and base libraries of the Polytechnique Montreal Modula-3 distribution

DIST_SUBDIR=	pm3
WRKSRC=		${WRKDIR}/pm3-base-${PORTVERSION}
INSTALL_TARGET=	all
MAKE_ARGS+=	M3OPTIONS="-DBUILD_ALL -DSHIP_ALL"
MAN1=		m3bundle.1
PLIST_SUB+=	SOVERSION=${SOVERSION} TARGET=${TARGET} \
		TARGETDIR=${TARGETDIR} WORDSIZE=${WORDSIZE}
SCRIPTS_ENV+=	TARGET=${TARGET}
USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/pm3-${PORTVERSION}

PROGS=		bin/m3build \
		bin/m3bundle \
		bin/m3coco \
		bin/m3ship \
		bin/m3tosgml \
		bin/sgmlconv \
		bin/sgmllinear \
		bin/sgmlnormalize \
		bin/sgmlstructure \
		bin/sgmltom3 \
		lib/m3/${TARGET}/m3cgc1
SOVERSION=	7

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

.if ${PORTOBJFORMAT} == "aout"
TARGET=		FreeBSD2
TARGETDIR=	freebsd-2
WORDSIZE=	32
BOOTSTRAP=	pm3-${PORTVERSION}-${TARGET}-boot.tar.bz2
.elif ${ARCH} == "i386"
.if ${OSVERSION} < 400011
TARGET=		FreeBSD3
TARGETDIR=	freebsd-3
BOOTSTRAP=	pm3-${PORTVERSION}-${TARGET}-boot.tar.bz2
.else
TARGET=		FreeBSD4
TARGETDIR=	freebsd-4
BOOTSTRAP=	pm3-${PORTVERSION}-${TARGET}-boot.tar.bz2
.endif
WORDSIZE=	32
.elif ${ARCH} == "alpha"
.if ${OSVERSION} < 400011
IGNORE=		Not supported on older versions of FreeBSD/Alpha
.endif
CFLAGS+=	-mieee
TARGET=		FBSD_ALPHA
TARGETDIR=	fbsd-alpha
WORDSIZE=	64
BOOTSTRAP=	pm3-${PORTVERSION}-${TARGET}-boot.tar.bz2
.endif

EXTRA_PATCHES!= echo ${PATCHDIR}/${TARGET}-patch-*
.if ${EXTRA_PATCHES} == ${PATCHDIR}/${TARGET}-patch-*
.undef EXTRA_PATCHES
.endif

.if !defined(TARGET)
pre-fetch:
	@${ECHO_MSG} "Cannot determine M3 target for this architecture"
	@${FALSE}
.endif

post-patch:
	@${CP} ${WRKSRC}/libs/m3core/src/runtime/${TARGET}/RTHeapDepC.c \
	    ${WRKSRC}/boot-${TARGET}/m3core/${TARGET}/RTHeapDepC.c

do-build:
	@${ECHO_MSG} "This port does everything in the install step."
	@${ECHO_MSG} "The build step is a no-op."

pre-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/check_conflicts

do-install:
	@${RM} -rf ${WRKSRC}/${TARGET}
	@(ulimit -d `ulimit -Hd` && ulimit -m `ulimit -Hm` && \
	    cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
	@for i in ${PROGS}; do ${STRIP_CMD} ${PREFIX}/$$i; done
	@${MKDIR} ${PREFIX}/share/pm3-base
	@${INSTALL_DATA} ${WRKSRC}/src/COPYRIGHT ${PREFIX}/share/pm3-base

.include <bsd.port.post.mk>
