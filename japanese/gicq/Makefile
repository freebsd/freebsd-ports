# New ports collection makefile for:	gicq
# Date Created:			31 Oct 1998
# Whom:				Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	gicq
PORTVERSION=	0.33
PORTREVISION=	1
CATEGORIES=	japanese net
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.korsoft.com/pub/gicq/
MASTER_SITE_SUBDIR=	flathill

PATCH_SITES=	http://download.sourceforge.net/gicq/ \
		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	flathill
PATCHFILES=	${DISTNAME}ja.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	flathill@FreeBSD.org
COMMENT=	GTK based ICQ program

LIB_DEPENDS=	icq.0:${PORTSDIR}/japanese/libicq

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gnome --disable-nls
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
