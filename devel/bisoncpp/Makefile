# $FreeBSD$

PORTNAME=	bisoncpp
PORTVERSION=	4.08.00
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/bisonc%2B%2B/${PORTVERSION}
DISTNAME=	bisonc++_${PORTVERSION}
EXTRACT_SUFX=	.orig.tar.gz

MAINTAINER=	5u623l20@gmail.com
COMMENT=	LALR(1) parser generator that generates C++ classes

LICENSE=	GPLv3

BUILD_DEPENDS=	icmake:${PORTSDIR}/devel/icmake \
		yodl>=3.0:${PORTSDIR}/textproc/yodl \
		libbobcat>=3.18:${PORTSDIR}/devel/libbobcat

DOCSDIR=	${PREFIX}/share/doc/bisonc++-${PORTVERSION}
PORTDOCS=	*

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

WRKSRC=		${WRKDIR}/bisonc++-${PORTVERSION}

USE_GCC=	yes

USES=		shebangfix

SHEBANG_LANG=	icmake
icmake_OLD_CMD=	/usr/bin/icmake
icmake_CMD=	${LOCALBASE}/bin/icmake

SHEBANG_FILES=	build \
		documentation/examples/bison++Example.NEW/make \
		documentation/man/calculator/build \
		documentation/manual/examples/calc/build \
		documentation/manual/examples/errorcalc/build \
		documentation/manual/examples/mfcalc/build \
		documentation/manual/examples/rpn/build \
		documentation/manual/grammar/poly/build \
		documentation/regression/run \
		parser/driver/build \
		scanner/driver/build

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g; \
		s|%%PORTVERSION%%|${PORTVERSION}|g' \
		${WRKSRC}/INSTALL.im
	@${REINPLACE_CMD} 's|"g++|"g++47|' \
		${WRKSRC}/INSTALL.im \
		${WRKSRC}/scanner/driver/build \
		${WRKSRC}/parser/driver/build
	@${REINPLACE_CMD} 's|"gcc|"gcc47|' \
		${WRKSRC}/icmake/special
	@${REINPLACE_CMD} 's|"cp -d |"cp -Pp | ; \
		s|"cp -r |"cp -R | ; \
		s|-doc|/doc|' \
		${WRKSRC}/icmake/install

do-build:
	@cd ${WRKSRC} && ./build program strip
	@cd ${WRKSRC} && ./build man
	@cd ${WRKSRC} && ./build manual

do-install:
	cd ${WRKSRC} && ./build install program ${STAGEDIR}
	cd ${WRKSRC} && ./build install man ${STAGEDIR}
	cd ${WRKSRC} && ./build install manual ${STAGEDIR}
	cd ${WRKSRC} && ./build install skel ${STAGEDIR}

.include <bsd.port.mk>
