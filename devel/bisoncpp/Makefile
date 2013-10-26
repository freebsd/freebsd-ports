# $FreeBSD$

PORTNAME=	bisoncpp
PORTVERSION=	4.01.00
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/bisonc%2B%2B/${PORTVERSION}
DISTNAME=	bisonc++_${PORTVERSION}
EXTRACT_SUFX=	.orig.tar.gz

MAINTAINER=	pgj@FreeBSD.org
COMMENT=	LALR(1) parser generator that generates C++ classes

LICENSE=	GPLv3

BUILD_DEPENDS=	icmake:${PORTSDIR}/devel/icmake \
		yodl>=3.0:${PORTSDIR}/textproc/yodl \
		libbobcat>=3:${PORTSDIR}/devel/libbobcat

.if !defined(NO_INSTALL_MANPAGES)
MANCOMPRESSED=	yes
MAN1=		bisonc++.1
.endif

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

WRKSRC=		${WRKDIR}/bisonc++-${PORTVERSION}

USE_GCC=	4.6

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} 's|"/usr"|"${PREFIX}"| ; \
		s|"/share/bisonc++"|"/share/${PORTNAME}-${PORTVERSION}"| ; \
		s|"/share/doc/bisonc++"|"/share/doc/${PORTNAME}-${PORTVERSION}"| ; \
		s|"/share/man/man1"|"/man/man1"| ; \
		s|"g++"|"g++46"|' \
		${WRKSRC}/INSTALL.im \
		${WRKSRC}/build
	@${REINPLACE_CMD} 's|#!/usr/bin/icmake|#!${LOCALBASE}/bin/icmake| ; \
		s|"g++|"g++46|' \
		${WRKSRC}/build \
		${WRKSRC}/scanner/driver/build \
		${WRKSRC}/parser/driver/build
	@${REINPLACE_CMD} 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/documentation/regression/run \
		${WRKSRC}/documentation/examples/bison++Example.NEW/make \
		${WRKSRC}/documentation/manual/examples/rpn/build \
		${WRKSRC}/documentation/manual/examples/errorcalc/build \
		${WRKSRC}/documentation/manual/examples/calc/build \
		${WRKSRC}/documentation/manual/examples/mfcalc/build \
		${WRKSRC}/documentation/man/calculator/build
	@${REINPLACE_CMD} 's|"cp -d |"cp -Pp | ; \
		s|"cp -r |"cp -R | ; \
		s|"-doc"|"/doc"|' \
		${WRKSRC}/icmake/install

do-build:
	@cd ${WRKSRC} && ./build program strip
.if !defined(NO_INSTALL_MANPAGES)
	@cd ${WRKSRC} && ./build man
.endif
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC} && ./build manual
.endif

do-install:
	cd ${WRKSRC} && ./build install program
.if !defined(NO_INSTALL_MANPAGES)
	cd ${WRKSRC} && ./build install man
.endif
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && ./build install manual
.endif

.include <bsd.port.mk>
