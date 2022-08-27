PORTNAME=	cairo
PORTVERSION=	1.17.7
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for GLib2

LICENSE=	GPLv2+ RUBY
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-native-package-installer>=1.0.3:devel/rubygem-native-package-installer \
		rubygem-pkg-config>=1.2.2:devel/rubygem-pkg-config \
		rubygem-red-colors>=0:graphics/rubygem-red-colors

USES=		gem gnome pkgconfig
USE_GNOME=	cairo
USE_RUBY=	yes

.include <bsd.port.mk>
