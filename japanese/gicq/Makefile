# New ports collection makefile for:	gicq
# Version required:		0.33
# Date Created:			31 Oct 1998
# Whom:				Seiichirou Hiraoka
#
# $FreeBSD$
#

DISTNAME=	gicq-0.33
PKGNAME=	ja-gicq-0.33
CATEGORIES=	japanese net
MASTER_SITES=	ftp://ftp.korsoft.com/pub/gicq/

PATCH_SITES=	http://www.freebsd.org/~flathill/distfiles/ \
		http://www-nagao.kuee.kyoto-u.ac.jp/member/taku/soft/
PATCHFILES=	gicq-0.33ja.patch
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
