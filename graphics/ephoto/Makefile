PORTNAME=	ephoto
DISTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	graphics enlightenment
MASTER_SITES=	https://download.enlightenment.org/rel/apps/${PORTNAME}/
DIST_SUBDIR=	enlightenment

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comprehensive Image Viewer Using EFL
WWW=		https://www.enlightenment.org/about-ephoto

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libefl.so:devel/efl

USES=		compiler:c11 desktop-file-utils meson pkgconfig tar:xz

.include <bsd.port.mk>
