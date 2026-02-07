PORTNAME=	vite_ruby
PORTVERSION=	3.9.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Use Vite in Ruby and bring joy to your JavaScript experience
WWW=		https://github.com/ElMassimo/vite_ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-dry-cli>=0.7<2:devel/rubygem-dry-cli \
		rubygem-logger-gitlab>=1.6<2:devel/rubygem-logger-gitlab \
		rubygem-mutex_m>=0:devel/rubygem-mutex_m \
		rubygem-rack-proxy>=0.6.1<1.0:www/rubygem-rack-proxy \
		rubygem-zeitwerk>=2.2<3:devel/rubygem-zeitwerk

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^3\.3\.

PLIST_FILES=	bin/vite

.include <bsd.port.mk>
