PORTNAME=	rustgis
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	graphics

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Fast, free and open-source GIS written in Rust
WWW=		https://rustgis.app/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	opengeos

WRKSRC=		${WRKDIR}/RustGIS-${PORTVERSION}

CARGO_ENV+=	RUSTGIS_DATA_DIR=${WRKSRC}/data

PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-cli

post-patch:
	${MKDIR} ${WRKSRC}/data
.for i in cities countries lakes rivers
	${CP} ${FILESDIR}/${i}.geojson ${WRKSRC}/data/
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/${PORTNAME}-cli ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-cli

.include <bsd.port.mk>
