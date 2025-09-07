PORTNAME=	atk
PORTVERSION=	4.3.3
CATEGORIES=	accessibility rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of ATK
WWW=		https://ruby-gnome.github.io/ \
		https://github.com/ruby-gnome/ruby-gnome

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
RUN_DEPENDS=	rubygem-glib2>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-glib2 \
		rubygem-rake>=0:devel/rubygem-rake

USES=		gem gnome
USE_GNOME=	atk

NO_ARCH=	yes

.include <bsd.port.mk>
