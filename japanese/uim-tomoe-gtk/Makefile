# New ports collection makefile for:   ja-uim-tomoe-gtk
# Date created:        9 Apr 2007
# Whom:                Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uim-tomoe-gtk
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=tomoe/23342

MAINTAINER=	ume@FreeBSD.org
COMMENT=	UIM helper program for Tomoe

LIB_DEPENDS=	tomoe.1:${PORTSDIR}/japanese/tomoe \
		tomoe-gtk.1:${PORTSDIR}/japanese/libtomoe-gtk \
		uim.4:${PORTSDIR}/textproc/uim

USE_GNOME=	lthack
USE_X_LIB=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/uim-tomoe-gtk
#PLIST_FILES+=	share/locale/ja/LC_MESSAGES/uim-tomoe-gtk.mo

.include <bsd.port.mk>
