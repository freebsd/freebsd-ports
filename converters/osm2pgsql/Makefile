# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osm2pgsql
PORTVERSION=	r29250
PORTREVISION=	2
CATEGORIES=	converters geography
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Convert OSM XML data to PostgreSQL database

LICENSE=	GPLv2

LIB_DEPENDS=	libproj.so:${PORTSDIR}/graphics/proj \
		libgeos.so:${PORTSDIR}/graphics/geos \
		libprotobuf-c.so:${PORTSDIR}/devel/protobuf-c

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf automake libtool aclocal autoheader libtoolize
USES=		gmake
USE_PGSQL=	yes
USE_GNOME=	libxml2

PLIST_FILES=	bin/nodecachefilereader \
		bin/osm2pgsql \
		man/man1/osm2pgsql.1.gz

PORTDOCS=	ChangeLog README AUTHORS TODO
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/m4/*.m4

run-autotools:
	cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ./autogen.sh

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
