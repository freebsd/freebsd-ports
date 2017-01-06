# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osm2pgsql
PORTVERSION=	0.87.2
PORTREVISION=	3
CATEGORIES=	converters geography

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Convert OSM XML data to PostgreSQL database

BROKEN=		Last update of graphics/geos broke compatibility

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libproj.so:graphics/proj \
		libgeos.so:graphics/geos \
		libprotobuf-c.so:devel/protobuf-c \
		libboost_thread.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	openstreetmap

USES=		autoreconf gmake libtool lua pgsql
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LUA="${LUA_CMD}" \
		LUA_INCLUDE="-I${LUA_INCDIR}" \
		LUA_LIB="-L${LUA_LIBDIR} -llua-${LUA_VER}" \
		--without-lockfree # workaround for build error
USE_GNOME=	libxml2

PLIST_FILES=	bin/nodecachefilereader \
		bin/osm2pgsql \
		man/man1/nodecachefilereader.1.gz \
		man/man1/osm2pgsql.1.gz

PORTDOCS=	ChangeLog README AUTHORS TODO
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/m4/*.m4
	@${REINPLACE_CMD} -e 's|AC_MSG_WARN|AC_MSG_ERROR|' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|-lstdc++||' ${WRKSRC}/Makefile.am

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
