# New ports collection makefile for:	xarchon
# Date created:		8 November 2002
# Whom:			Marc Fonvieille <blackend@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xarchon
PORTVERSION=	0.50
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.seul.org/pub/xarchon/ \
		http://xarchon.seul.org/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A chess-like strategy game with battle options

USE_XLIB=	yes
USE_GNOME=	esound gtk12
USE_GMAKE=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes

MAN6=	xarchon.6

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
