# New ports collection makefile for:	libicq
# Date Created:			22 Oct 1998
# Whom:				Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	libicq
PORTVERSION=	0.33
CATEGORIES=	japanese net
MASTER_SITES=	ftp://ftp.korsoft.com/pub/gicq/

PATCH_SITES=	${MASTER_SITE_LOCAL} \
		http://www-nagao.kuee.kyoto-u.ac.jp/member/taku/soft/
PATCH_SITE_SUBDIR=	flathill
PATCHFILES=	${DISTNAME}ja.patch
PATCH_DIST_STRIP= -p1

MAINTAINER=	flathill@FreeBSD.org

LIB_DEPENDS=    glib12.3:${PORTSDIR}/devel/glib12

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_LIBTOOL=	yes
CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
