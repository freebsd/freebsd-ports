PORTNAME=	osm2mp
PORTVERSION=	r475
PORTREVISION=	2
CATEGORIES=	converters geography
MASTER_SITES=	https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	OpenStreetMap data into Polish map format (MP) converter
WWW=		https://code.google.com/archive/p/osm2mp/

RUN_DEPENDS=	p5-YAML>=0:textproc/p5-YAML \
		p5-Encode-Locale>=0:converters/p5-Encode-Locale \
		p5-Math-Polygon>=0:math/p5-Math-Polygon \
		p5-Math-Polygon-Tree>=0:math/p5-Math-Polygon-Tree \
		p5-Tree-R>=0:devel/p5-Tree-R \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-Math-Geometry-Planar-GPC-PolygonXS>=0:math/p5-Math-Geometry-Planar-GPC-PolygonXS \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils

LICENSE=	GPLv2

USES=		tar:bzip2 perl5 shebangfix
SHEBANG_FILES=	${WRKSRC}/osm2mp.pl
USE_PERL5=	run
NO_BUILD=	yes

SUB_FILES=	pkg-message

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|garmin.yml|${DATADIR}/&|; s|GPC::Polygon|&XS|' \
		${WRKSRC}/osm2mp.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/osm2mp.pl ${STAGEDIR}${PREFIX}/bin/osm2mp
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} '*.cmap *.yml *.txt *.typ polish-mp' ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
