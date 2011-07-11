# New ports collection Makefile for:	fxite
# Date created:				23 August 2010
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	fxite
PORTVERSION=	0.6
PORTREVISION=	23
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An advanced cross-platform text editor

LIB_DEPENDS=	fxscintilla.22:${PORTSDIR}/x11-toolkits/fxscintilla

BROKEN=		does not compile

USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -lintl"

PLIST_FILES=	bin/fxite

.include <bsd.port.mk>
