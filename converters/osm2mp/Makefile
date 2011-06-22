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
COMMENT=	OpenStreetMap data into Polish map format (MP) convertor

RUN_DEPENDS=	${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/Encode/Locale.pm:${PORTSDIR}/converters/p5-Encode-Locale \
		${SITE_PERL}/Math/Polygon.pm:${PORTSDIR}/math/p5-Math-Polygon \
		${SITE_PERL}/Math/Polygon/Tree.pm:${PORTSDIR}/math/p5-Math-Polygon-Tree \
		${SITE_PERL}/Tree/R.pm:${PORTSDIR}/devel/p5-Tree-R \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/${PERL_ARCH}/Math/Geometry/Planar/GPC/Polygon.pm:${PORTSDIR}/math/p5-Math-Geometry-Planar-GPC-Polygon \
		${SITE_PERL}/${PERL_ARCH}/List/MoreUtils.pm:${PORTSDIR}/lang/p5-List-MoreUtils

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
