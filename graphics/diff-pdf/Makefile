PORTNAME=	diff-pdf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.2
PORTREVISION=	6
CATEGORIES=	graphics

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Tool for visually comparing two PDFs
WWW=		https://vslavik.github.io/diff-pdf/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib \
		libpoppler.so:graphics/poppler

USES=		autoreconf compiler:c++11-lang gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	vslavik
USE_GNOME=	cairo glib20
USE_WX=		3.0+

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
