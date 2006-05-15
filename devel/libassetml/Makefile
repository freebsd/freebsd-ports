# New ports collection makefile for:	libassetml
# Date created:			2 Dec 2003
# Whom:				Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libassetml
PORTVERSION=	1.2.1
PORTREVISION=	5
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ofset

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Devel Library to share image and audio files between projects

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt
BUILD_DEPENDS=	texi2html:${PORTSDIR}/textproc/texi2html

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack lthack gnomeprefix gnometarget glib20 libxml2 pkgconfig
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib

INFO=	libassetml

post-install:
	@${MKDIR} ${PREFIX}/share/gnome/assetml

.include <bsd.port.mk>
