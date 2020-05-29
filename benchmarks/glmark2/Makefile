# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glmark2
PORTVERSION=	2020.04
CATEGORIES=	benchmarks

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Benchmark for OpenGL (ES) 2.0

LICENSE=	GPLv3

LIB_DEPENDS=	libpng.so:graphics/png

USES=		compiler:c++11-lang gl jpeg localbase:ldflags pkgconfig \
		waf xorg
USE_XORG=	x11
USE_GL=		egl gl glesv2
USE_GITHUB=	yes
GH_TAGNAME=	06e4728
CONFIGURE_ARGS=	--with-flavors=x11-gl,x11-glesv2 --no-opt --no-debug

PORTDOCS=	NEWS

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/-std=c++/s,14,11,' ${WRKSRC}/wscript
	@${REINPLACE_CMD} -e "/lib/s/, 'dl'//" ${WRKSRC}/src/wscript_build
	@${REINPLACE_CMD} -e 's/GLMARK_VERSION/ &/' \
		${WRKSRC}/src/native-state-x11.cpp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
