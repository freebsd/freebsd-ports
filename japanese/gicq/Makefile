# New ports collection makefile for:	gicq
# Date Created:			31 Oct 1998
# Whom:				Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	gicq
PORTVERSION=	0.33
CATEGORIES=	japanese net
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.korsoft.com/pub/gicq/
MASTER_SITE_SUBDIR=	flathill

PATCH_SITES=	${MASTER_SITE_LOCAL} \
		http://www-nagao.kuee.kyoto-u.ac.jp/member/taku/soft/
PATCH_SITE_SUBDIR=	flathill
PATCHFILES=	${DISTNAME}ja.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	flathill@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12	\
		icq.0:${PORTSDIR}/japanese/libicq

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gnome --disable-nls
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
