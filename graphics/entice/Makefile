PORTNAME=	entice
PORTVERSION=	g20240127
CATEGORIES=	graphics enlightenment
DIST_SUBDIR=	enlightenment

MAINTAINER=	peter@flytrace.com
COMMENT=	Simple Image Viewer Using EFL
WWW=		https://github.com/vtorri/entice

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libefl.so:devel/efl \
		libexif.so:graphics/libexif

USES=		compiler:c11 desktop-file-utils meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	vtorri
GH_PROJECT=	entice
GH_TAGNAME=	5122896

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=		yes

NLS_USES=	gettext-runtime
NLS_MESON_TRUE=	nls

.include <bsd.port.mk>
