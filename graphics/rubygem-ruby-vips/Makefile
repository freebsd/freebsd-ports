# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ruby-vips
PORTVERSION=	2.0.17
PORTREVISION=	1
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Binding for the vips image processing library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libvips.so:graphics/vips
RUN_DEPENDS=	rubygem-ffi>=1.9<2:devel/rubygem-ffi

USES=		gem gnome shebangfix
USE_GNOME=	glib20
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	install-vips.sh \
		example/*.rb

.include <bsd.port.mk>
