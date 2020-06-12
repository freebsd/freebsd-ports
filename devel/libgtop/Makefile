# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgtop
PORTVERSION=	2.40.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME top library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PERL5=	build
USE_XORG=	xau
USES=		gettext gmake gnome libtool makeinfo pathfix perl5 \
		pkgconfig tar:xz xorg
USE_GNOME=	gnomeprefix glib20 intlhack introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-introspection

INFO=		libgtop2

PKGMESSAGE=	${FILESDIR}/pkg-message

.include <bsd.port.mk>
