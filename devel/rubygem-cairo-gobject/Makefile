PORTNAME=	cairo-gobject
PORTVERSION=	4.3.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of cairo-gobject
WWW=		https://ruby-gnome.github.io/ \
		https://github.com/ruby-gnome/ruby-gnome

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

RUN_DEPENDS=	rubygem-cairo>=1.16.2:graphics/rubygem-cairo \
		rubygem-glib2>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-glib2

USES=		gem gnome
USE_GNOME=	cairo glib20

.include <bsd.port.mk>
