# New ports collection makefile for:	libicq
# Date Created:			22 Oct 1998
# Whom:				Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	libicq
PORTVERSION=	0.33
CATEGORIES=	japanese net
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.korsoft.com/pub/gicq/
MASTER_SITE_SUBDIR=	flathill

PATCH_SITES=	${MASTER_SITE_LOCAL} \
		http://www-nagao.kuee.kyoto-u.ac.jp/member/taku/soft/
PATCH_SITE_SUBDIR=	flathill
PATCHFILES=	${DISTNAME}ja.patch
PATCH_DIST_STRIP= -p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to add ICQ communication support to your software

USE_GNOME=	glib12
USE_INC_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
