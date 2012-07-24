# New ports collection makefile for:	osm2mp
# Date created:		21 Jun 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osm2mp
PORTVERSION=	r475
CATEGORIES=	converters geography
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	OpenStreetMap data into Polish map format (MP) converter

RUN_DEPENDS=	p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-Encode-Locale>=0:${PORTSDIR}/converters/p5-Encode-Locale \
		p5-Math-Polygon>=0:${PORTSDIR}/math/p5-Math-Polygon \
		p5-Math-Polygon-Tree>=0:${PORTSDIR}/math/p5-Math-Polygon-Tree \
		p5-Tree-R>=0:${PORTSDIR}/devel/p5-Tree-R \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Math-Geometry-Planar-GPC-Polygon>=0:${PORTSDIR}/math/p5-Math-Geometry-Planar-GPC-Polygon \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|garmin.yml|${DATADIR}/&|' ${WRKSRC}/osm2mp.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/osm2mp.pl ${PREFIX}/bin/osm2mp
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} '*.cmap *.yml *.txt *.typ polish-mp' ${DATADIR}/
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
