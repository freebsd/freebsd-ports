# New ports collection makefile for: ja-gtkicq
# Date created: 8 MAY 1999
# Whom: Shuichi Tanaka
#
# $FreeBSD$
#

PORTNAME=	gtkicq
PORTVERSION=	0.60
PORTREVISION=	5
CATEGORIES=	japanese net
MASTER_SITES=	ftp://gtkicq.pn.org/pub/gtkicq/

PATCH_SITES=	http://keemun.soraneko.com/gtkicq/archives/
PATCHFILES=	${DISTNAME}-ja.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	stanaka@bb.mbn.or.jp
COMMENT=	Icq clone for Japanese user

BUILD_DEPENDS=	${LOCALBASE}/lib/libjcode.a:${PORTSDIR}/japanese/libjcode

USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gnome --datadir=${PREFIX}/share/gtkicq
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
