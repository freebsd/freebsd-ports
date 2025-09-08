PORTNAME=	gio2
PORTVERSION=	4.3.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of gio 2.x
WWW=		https://ruby-gnome.github.io/ \
		https://github.com/ruby-gnome/ruby-gnome

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

RUN_DEPENDS=	rubygem-fiddle>=0:devel/rubygem-fiddle \
		rubygem-gobject-introspection>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-gobject-introspection

USES=		gem gnome
USE_GNOME=	glib20

.include <bsd.port.mk>
