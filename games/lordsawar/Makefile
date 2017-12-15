# $FreeBSD$

PORTNAME=	lordsawar
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Warlords II clone

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib gettext gmake libarchive pkgconfig shebangfix
USE_GNOME=	gtkmm30 intltool libxslt
USE_GSTREAMER=	mm
USE_CXXSTD=	c++11
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
SHEBANG_FILES=	create-lw-file
bash_CMD=	/bin/sh

BROKEN_aarch64=	Fails to build: runaway process

.include <bsd.port.mk>
