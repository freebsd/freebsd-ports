# Created by: alanp@unixpower.org
# $FreeBSD$

PORTNAME=	xaric
PORTVERSION=	0.13.6
CATEGORIES=	irc
MASTER_SITES=	http://xaric.org/software/xaric/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC Client similer to BitchX or ircII

USES=		pathfix gmake
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-ggdb3||g' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xaric ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xaric.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}/help
	${INSTALL_DATA} ${WRKSRC}/help/* ${STAGEDIR}${DATADIR}/help

.include <bsd.port.mk>
