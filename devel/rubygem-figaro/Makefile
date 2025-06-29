PORTNAME=	figaro
PORTVERSION=	1.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, Heroku-friendly Rails app configuration using ENV and a single YAML file
WWW=		https://github.com/laserlemon/figaro

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-thor>=0.14.0<2:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/figaro

.include <bsd.port.mk>
