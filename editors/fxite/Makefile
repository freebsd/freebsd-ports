# New ports collection Makefile for:	fxite
# Date created:				23 August 2010
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	fxite
PORTVERSION=	0.6
PORTREVISION=	22
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An advanced cross-platform text editor

LIB_DEPENDS=	fxscintilla.21:${PORTSDIR}/x11-toolkits/fxscintilla

USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -lintl"

PLIST_FILES=	bin/fxite

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 701101
BROKEN=		does not build on pre 701101; needs strndup
.endif

.include <bsd.port.post.mk>
