# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glmark2
PORTVERSION=	2014.03
CATEGORIES=	benchmarks
MASTER_SITES=	https://launchpadlibrarian.net/169075003/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Benchmark for OpenGL (ES) 2.0

LICENSE=	GPLv3

LIB_DEPENDS=	libpng.so:graphics/png

USES=		jpeg localbase pkgconfig waf
USE_GL=		egl gl glesv2
CONFIGURE_ARGS=	--with-flavors=x11-gl,x11-glesv2 --no-opt --no-debug
WAF_CMD=	./waf -v

PORTDOCS=	NEWS

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "/lib/s/, 'dl'//" ${WRKSRC}/src/wscript_build

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
