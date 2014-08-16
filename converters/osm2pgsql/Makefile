# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osm2pgsql
PORTVERSION=	0.84.0
PORTREVISION=	5
CATEGORIES=	converters geography

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Convert OSM XML data to PostgreSQL database

LICENSE=	GPLv2

LIB_DEPENDS=	libproj.so:${PORTSDIR}/graphics/proj \
		libgeos.so:${PORTSDIR}/graphics/geos \
		libprotobuf-c.so:${PORTSDIR}/devel/protobuf-c

USE_GITHUB=	yes
GH_ACCOUNT=	openstreetmap
GH_COMMIT=	237b125

USES=		gmake libtool lua pgsql tar:bzip2
USE_AUTOTOOLS=	autoconf automake aclocal autoheader libtoolize
AUTOMAKE_ARGS=	-a -c -f
CONFIGURE_ARGS=	LUA="${LUA_CMD}" \
		LUA_INCLUDE="-I${LUA_INCDIR}" \
		LUA_LIB="-L${LUA_LIBDIR} -llua-${LUA_VER}"
USE_GNOME=	libxml2

PLIST_FILES=	bin/nodecachefilereader \
		bin/osm2pgsql \
		man/man1/nodecachefilereader.1.gz \
		man/man1/osm2pgsql.1.gz

PORTDOCS=	ChangeLog README AUTHORS TODO
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/m4/*.m4

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
