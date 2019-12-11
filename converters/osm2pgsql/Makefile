# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osm2pgsql
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	converters geography

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Convert OSM XML data to PostgreSQL database

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libproj.so:graphics/proj \
		libboost_system.so:devel/boost-libs \
		libexpat.so:textproc/expat2

USE_GITHUB=	yes
GH_ACCOUNT=	openstreetmap

USES=		cmake compiler:c++11-lang pgsql

PLIST_FILES=	bin/osm2pgsql \
		man/man1/osm2pgsql.1.gz

PORTDOCS=	AUTHORS ChangeLog README.md
PORTDATA=	*

OPTIONS_DEFINE=	DOCS LUAJIT

LUAJIT_DESC=		Build with LuaJIT support
LUAJIT_CMAKE_BOOL=	WITH_LUAJIT
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_USES_OFF=	lua:53

post-patch:
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|' ${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
