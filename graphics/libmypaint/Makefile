PORTNAME=	libmypaint
DISTVERSION=	1.6.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/mypaint/libmypaint/releases/download/v${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Brush library from the MyPaint project
WWW=		http://mypaint.org/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-c.so:devel/json-c

USES=		compiler:c11 gmake gnome libtool localbase pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

TEST_TARGET=	check

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	NLS OPENMP
OPTIONS_DEFAULT_amd64=	OPENMP
OPTIONS_DEFAULT_powerpc64=	OPENMP
OPTIONS_DEFAULT_powerpc64le=	OPENMP

NLS_USES=	gettext
NLS_USE=	GNOME=intltool
NLS_CONFIGURE_ENABLE=	nls i18n

OPENMP_CONFIGURE_ENABLE=	openmp

.include <bsd.port.mk>
