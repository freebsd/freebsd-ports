# New ports collection makefile for:	ja-tomoe
# Date created:				18 Dec 2005
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tomoe
PORTVERSION=	0.4.0
#PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=tomoe/22893

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Tegaki Online MOji-ninshiki Engine

USE_GNOME=	lthack gnomehack
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes

CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

.include <bsd.port.mk>
