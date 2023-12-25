PORTNAME=	cairo
PORTVERSION=	1.17.13
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for GLib2
WWW=		https://rcairo.github.io/ \
		https://github.com/rcairo/rcairo

LICENSE=	GPLv2+ RUBY
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-native-package-installer>=1.0.3:devel/rubygem-native-package-installer \
		rubygem-pkg-config>=1.2.2:devel/rubygem-pkg-config \
		rubygem-red-colors>=0:graphics/rubygem-red-colors

USES=		gem gnome pkgconfig
USE_GNOME=	cairo

.include <bsd.port.mk>
