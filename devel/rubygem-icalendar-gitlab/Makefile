PORTNAME=	icalendar
PORTVERSION=	2.12.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Library for working with iCalendar files
WWW=		https://github.com/icalendar/icalendar

LICENSE=	BSD2CLAUSE GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-ice_cube>=0.16<1:devel/rubygem-ice_cube \
		rubygem-logger-gitlab>=0:devel/rubygem-logger-gitlab \
		rubygem-ostruct>=0:devel/rubygem-ostruct

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
