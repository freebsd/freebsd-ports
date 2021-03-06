# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	data.table
DISTVERSION=	1.14.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Extension of Data.frame

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cran:auto-plist

OPTIONS_DEFINE=		OPENMP
OPTIONS_DEFAULT=	OPENMP

OPENMP_CONFIGURE_ENABLE=	openmp

NO_ARCH_IGNORE=		datatable.so

.include <bsd.port.options.mk>

.if ${ARCH} == i386 && ${OSVERSION} < 1202000
# See PR 230888 : Missing 64 bit atomic functions for i386
USES+=		compiler:gcc-c++11-lib
.elif defined(PPC_ABI) && ${PPC_ABI} == ELFv1
USE_GCC=	yes
.else
USES+=		cran:compiles
.endif

.if ${ARCH} == i386 && ${OSVERSION} < 1202000
# See PR 230888 : Missing 64 bit atomic functions for i386
post-patch:
	@${REINPLACE_CMD} -e '/^PKG_LIBS/s|$$| -latomic|' \
		${WRKSRC}/src/Makevars.in
.endif

.include <bsd.port.mk>
