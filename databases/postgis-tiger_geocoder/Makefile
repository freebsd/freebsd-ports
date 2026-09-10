PORTNAME=	postgis_tiger_geocoder
DISTVERSION=	2025.2rc1
CATEGORIES=	databases geography
MASTER_SITES=	https://gitea.osgeo.org/postgis/postgis_tiger_geocoder/releases/download/${DISTVERSION}/

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	PostGIS TIGER geocoder and reverse geocoder
WWW=		https://gitea.osgeo.org/postgis/postgis_tiger_geocoder

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pgsql:16+
WANT_PGSQL=	server

RUN_DEPENDS=	${LOCALBASE}/share/postgresql/extension/postgis.control:databases/postgis37

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV=	USE_PGXS=1

PLIST_FILES=	share/postgresql/extension/postgis_tiger_geocoder.sql \
		share/postgresql/extension/postgis_tiger_geocoder--2025.2.sql \
		share/postgresql/extension/postgis_tiger_geocoder--2025.2--ANY.sql \
		share/postgresql/extension/postgis_tiger_geocoder--ANY--2025.2.sql \
		share/postgresql/extension/postgis_tiger_geocoder.control

.for version in 3.2.10 3.3.10 3.4.6 3.5.4 3.5.5 3.5.6 3.5.7 3.6.0 3.6.1 3.6.2 3.6.3 3.6.4 2025.1
PLIST_FILES+=	share/postgresql/extension/postgis_tiger_geocoder--${version}--ANY.sql
.endfor

.include <bsd.port.mk>
