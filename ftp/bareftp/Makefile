# Created by: Chris Petrik (chris@officialunix.com)
# $FreeBSD$

PORTNAME=	bareftp
PORTVERSION=	0.3.12
CATEGORIES=	ftp
MASTER_SITES=	http://www.bareftp.org/release/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FTP client made in C sharp

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datarootdir="${PREFIX}/share" \
		--libdir="${PREFIX}/lib" \
		--localedir="${PREFIX}/share/locale" \
		--includedir="${LOCALBASE}/include"
INSTALL_TARGET=	install-strip

INSTALLS_ICONS=	yes
USES=		cpe gettext gmake libtool pkgconfig
USE_GNOME=	gtksharp20 gnomesharp20 intltool

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GNOMEKEYRING NLS
OPTIONS_DEFAULT=GNOMEKEYRING
OPTIONS_SUB=	yes

GNOMEKEYRING_CONFIGURE_WITH=	gnomekeyring
GNOMEKEYRING_BUILD_DEPENDS=	gnome-keyring-sharp>0:security/gnome-keyring-sharp
GNOMEKEYRING_RUN_DEPENDS=	gnome-keyring-sharp>0:security/gnome-keyring-sharp
NLS_CONFIGURE_ENABLE=	nls

# TODO
# Ugly way but configure ignore "--localedir=" fu* ;/
pre-build:
	@${REINPLACE_CMD} -e 's|$$(prefix)/$$(DATADIRNAME)|${PREFIX}/share|g' \
		${WRKSRC}/po/Makefile

.include <bsd.port.mk>
