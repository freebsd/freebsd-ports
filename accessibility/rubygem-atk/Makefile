PORTNAME=	atk
PORTVERSION=	4.0.1
CATEGORIES=	accessibility rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of ATK
WWW=		https://ruby-gnome.github.io/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
RUN_DEPENDS=	rubygem-glib2>=${PORTVERSION}:devel/rubygem-glib2

USES=		gem gnome
USE_GNOME=	atk
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
