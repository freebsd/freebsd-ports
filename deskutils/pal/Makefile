PORTNAME=	pal
DISTVERSION=	0.4.3
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}cal/${PORTNAME}/${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Calendar application
WWW=		https://palcal.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake gnome ncurses pkgconfig readline tar:tgz
USE_GNOME=	glib20

MAKE_ARGS=	prefix=${PREFIX}
ALL_TARGET=
BINARY_ALIAS=	make=gmake

.include <bsd.port.mk>
