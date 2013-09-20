# Created by: johans
# $FreeBSD$

PORTNAME=	clive
PORTVERSION=	0.4.10
CATEGORIES=	deskutils
MASTER_SITES=	SF/lj${PORTNAME}/lj${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A command line client for posting LiveJournal entries

USES=	iconv

MAN1=	clive.1

GNU_CONFIGURE=	yes

CONFLICTS=	*clive-[1-9]*
LATEST_LINK=	ljclive

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} 's/iconv "iconv/"iconv/' ${WRKSRC}/configure

.include <bsd.port.post.mk>
