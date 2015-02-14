# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/branches/GNOME_3_12/devel/gitg/Makefile 19822 2014-08-20 08:57:46Z gusi $

PORTNAME=	gitg
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK-based git repository viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		git:${PORTSDIR}/devel/git

CONFLICTS=	gitg0-[0-9]*

USES=		tar:xz gettext gmake pkgconfig pathfix libtool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
