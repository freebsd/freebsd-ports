PORTNAME=	entice
PORTVERSION=	0.1.0
CATEGORIES=	graphics enlightenment
MASTER_SITES=   http://download.enlightenment.org/rel/apps/${PORTNAME}/
DIST_SUBDIR=	enlightenment

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Simple Image Viewer Using EFL
WWW=		https://www.enlightenment.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libefl.so:devel/efl \
		libexif.so:graphics/libexif

USES=		compiler:c11 desktop-file-utils meson localbase:ldflags pkgconfig tar:xz

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=		yes

NLS_USES=	gettext-runtime
NLS_MESON_TRUE=	nls

.include <bsd.port.mk>
