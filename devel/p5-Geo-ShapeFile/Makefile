# Created by: estith
# $FreeBSD$

PORTNAME=	Geo-ShapeFile
PORTVERSION=	2.66
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Extension for handling ESRI GIS Shapefiles

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Tree-R>0:devel/p5-Tree-R \
		p5-autovivification>0:devel/p5-autovivification

NO_ARCH=	yes
USES=		dos2unix perl5
DOS2UNIX_GLOB=	*.pm *.pl *.t
USE_PERL5=	configure

.include <bsd.port.mk>
