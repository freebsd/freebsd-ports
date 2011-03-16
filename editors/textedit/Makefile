# New ports collection makefile for:	textedit
# Date created:		3 January 1998
# Whom:			jraynard
#
# $FreeBSD$
#

PORTNAME=	textedit
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The OpenLook textedit application

DEPRECATED=	Upstream disapear and distfile is no more available
EXPIRATION_DATE=	2011-05-01

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

WRKSRC=		${WRKDIR}/textedit
USE_IMAKE=	yes
USE_XORG=	x11 xext
MAN1=		textedit.1
PLIST_FILES=	bin/textedit

.include <bsd.port.mk>
