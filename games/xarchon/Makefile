# New ports collection makefile for:	xarchon
# Date created:		8 November 2002
# Whom:			Marc Fonvieille <blackend@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xarchon
PORTVERSION=	0.50
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.seul.org/pub/xarchon/ \
		http://xarchon.seul.org/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	blackend@FreeBSD.org
COMMENT=	A chess-like strategy game with battle options

USE_XLIB=	yes
USE_GNOME=	esound gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN6=	xarchon.6

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 3
LIB_DEPENDS+=	Xpm.4:${PORTSDIR}/graphics/xpm
.endif

.include <bsd.port.post.mk>
