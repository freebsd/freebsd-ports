# New ports collection makefile for:	kasumi
# Date Created:				10 January 2005
# Whom:					MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kasumi
PORTVERSION=	0.8
#PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	${PORTNAME}/14191

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A dictionary management tool for anthy

USE_X_PREFIX=	yes
USE_GNOME=	gnomehier gtk20
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
