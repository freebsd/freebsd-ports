PORTNAME=	ruby-vips
PORTVERSION=	2.2.5
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Binding for the vips image processing library
WWW=		https://github.com/libvips/ruby-vips

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libvips.so:graphics/vips@${FLAVOR}
RUN_DEPENDS=	rubygem-ffi>=1.12<2:devel/rubygem-ffi \
		rubygem-logger>=0:devel/rubygem-logger

USES=		gem gnome shebangfix
USE_GNOME=	glib20

NO_ARCH=	yes

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	-nox11

SHEBANG_FILES=	example/*.rb

.include <bsd.port.mk>
