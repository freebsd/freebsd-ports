PORTNAME=	vite_rails
PORTVERSION=	3.0.17
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails70

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Use Vite in Rails and bring joy to your JavaScript experience
WWW=		https://github.com/ElMassimo/vite_ruby \
		https://github.com/ElMassimo/vite_ruby/tree/vite_rails@3.0.16/vite_rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-railties70>=5.1<8:www/rubygem-railties70 \
		rubygem-vite_ruby>=3.2.2<4:devel/rubygem-vite_ruby

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
