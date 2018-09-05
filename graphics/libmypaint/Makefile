# $FreeBSD$

PORTNAME=	libmypaint
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/mypaint/libmypaint/releases/download/v${PORTVERSION}/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Brush library from the MyPaint project

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-c.so:devel/json-c

USES=		gmake gnome libtool localbase pkgconfig tar:xz
USE_GNOME=	glib20 intltool introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

TEST_TARGET=	check

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
