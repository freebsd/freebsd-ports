# New ports collection makefile for:   gprolog
# Date created:        30 June 2001
# Whom:                Douglas Anestad <yotta@dougdidit.com>
#
# $FreeBSD$
#

PORTNAME=	gprolog
PORTVERSION=	1.2.16
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	yotta@dougdidit.com

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--disable-linedit

PLIST_SUB+=	GPROLOG_VER=1.2.16

GNU_CONFIGURE=	yes
AUTOCONF=	autoconf
USE_AUTOCONF_VER=	253
AUTOCONF_DIR=	${LOCALBASE}/share/autoconf
WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_GMAKE=	yes

.include <bsd.port.post.mk>
