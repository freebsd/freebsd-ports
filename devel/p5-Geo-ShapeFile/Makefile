# Created by: estith
# $FreeBSD$

PORTNAME=	Geo-ShapeFile
PORTVERSION=	2.60
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Perl extension for handling ESRI GIS Shapefiles

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Tree-R>0:${PORTSDIR}/devel/p5-Tree-R \
		p5-autovivification>0:${PORTSDIR}/devel/p5-autovivification
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
