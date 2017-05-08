# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aylet
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.worldofspectrum.org/pub/sinclair/music/players-unix/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Aylet plays music files in the .ay format

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext-runtime pkgconfig

OPTIONS_DEFINE=	GUI
OPTIONS_DEFAULT=GUI
OPTIONS_SUB=	yes

GUI_USE=	XORG=x11,xext,xi GNOME=gtk12

ALL_TARGET=	aylet
GUI_ALL_TARGET=	xaylet

PLIST_FILES=	bin/aylet %%GUI%%bin/xaylet man/man1/aylet.1.gz

.include <bsd.port.mk>
