# $FreeBSD$

PORTNAME=	ephoto
DISTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	https://download.enlightenment.org/rel/apps/${PORTNAME}/
DIST_SUBDIR=	enlightenment

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Comprehensive Image Viewer Using EFL

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libefl.so:devel/efl

USES=		compiler:c11 desktop-file-utils pkgconfig tar:xz
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
