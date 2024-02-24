PORTNAME=	gnugo
PORTVERSION=	3.8
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	GNU

MAINTAINER=	spcoltri@omcl.org
COMMENT=	The game of Go
WWW=		https://www.gnu.org/software/gnugo/

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		gmake

INFO=		gnugo
PLIST_FILES=	bin/gnugo \
		share/man/man6/gnugo.6.gz

post-extract:
	${RM} ${WRKSRC}/doc/gnugo.info*

.include <bsd.port.mk>
