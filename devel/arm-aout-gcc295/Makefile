# ex:ts=8
# New ports collection makefile for:	armgcc-2.95.2
# Date created:		22 Aug 2000
# Whom:			Paul Becke <pbecke@javagear.com>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.95.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/${DISTNAME}
PKGNAMEPREFIX=	arm-aout-
PKGNAMESUFFIX=	295
DISTFILES=	gcc-core-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g++-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	pbecke@javagear.com

BROKEN=		"Does not build"

GCC_REV=	${DISTNAME:S/gcc-//g}
PLIST_SUB+=	GCC_REV=${GCC_REV}
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=arm-aout --with-gnu-as --with-gnu-ld --with-newlib \
		--enable-languages="c,c++"
.if defined(DEFAULT_CPU)
CONFIGURE_ARGS+=--with-cpu="${DEFAULT_CPU}"
.endif
MAKE_FLAGS=	LANGUAGES="c c++"

.if !defined(DEFAULT_CPU)
pre-extract:
	@${ECHO}
	@${ECHO} "You can specify a default cpu target for gcc by setting DEFAULT_CPU to the"
	@${ECHO} "appropriate target (e.g., strongarm1100)."
	@${ECHO}
.endif

post-extract:
	${MKDIR} ${WRKSRC}/gcc/target
	${LN} -s ${FILESDIR}/include ${WRKSRC}/gcc/target/include

do-configure:
	cd ${WRKSRC}/libiberty ; ./configure ${CONFIGURE_ARGS}
	cd ${WRKSRC}/gcc ; ./configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC}/libiberty ; ${GMAKE}
	cd ${WRKSRC}/gcc ; ${GMAKE}

do-install:
	cd ${WRKSRC}/gcc ; ${GMAKE} install
	${LN} -f ${PREFIX}/bin/arm-aout-g++ ${PREFIX}/arm-aout/bin/g++
	${LN} -f ${PREFIX}/bin/arm-aout-c++filt ${PREFIX}/arm-aout/bin/c++filt
	@${MV} ${PREFIX}/bin/cpp ${PREFIX}/bin/${PKGNAMEPREFIX}cpp
	@${MV} ${PREFIX}/bin/gcov ${PREFIX}/bin/${PKGNAMEPREFIX}gcov

.include <bsd.port.mk>
