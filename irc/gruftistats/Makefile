PORTNAME=	gruftistats
PORTVERSION=	0.2.4
PORTREVISION=	2
CATEGORIES=	irc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Produces a web page of statistics and quotes from IRC channel logs
WWW=		https://gruftistats.sourceforge.net/

USES=	gmake

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's,strcasestr,strcasestr_x,g' ${WRKSRC}/ircstats.h \
		${WRKSRC}/lib.c

.include <bsd.port.mk>
