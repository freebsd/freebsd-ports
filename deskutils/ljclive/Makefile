# Created by: johans
# $FreeBSD$

PORTNAME=	ljclive
PORTVERSION=	0.4.10
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}
DISTNAME=	clive-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A command line client for posting LiveJournal entries

USES=		iconv
GNU_CONFIGURE=	yes

CONFLICTS=	*clive-[1-9]*

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} 's/iconv "iconv/"iconv/' ${WRKSRC}/configure

.include <bsd.port.post.mk>
