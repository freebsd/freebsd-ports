# Created by: Shen Chuan-Hsing
# $FreeBSD$

PORTNAME=	fortunetw
PORTVERSION=	1.3
CATEGORIES=	chinese
MASTER_SITES=	LOCAL/chinsan \
		http://chinsan2.twbbs.org/distfiles/
DISTNAME=	zh-fortunetw-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Classic fortune file in Taiwan

NO_BUILD=	yes

STRCMD=		/usr/games/strfile

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/bsdchat ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/folksong ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/liuyong ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/stephehchow ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/tangshi ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/xiaoxing ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/yijing ${STAGEDIR}${PREFIX}/share/games/fortune

pre-install:
.if !exists(${STRCMD})
	@${ECHO_MSG}	"Please install the games distribution"
	@${FALSE}
.endif

post-install:
	${STRCMD} ${STAGEDIR}${PREFIX}/share/games/fortune/bsdchat
	${STRCMD} ${STAGEDIR}${PREFIX}/share/games/fortune/folksong
	${STRCMD} ${STAGEDIR}${PREFIX}/share/games/fortune/liuyong
	${STRCMD} ${STAGEDIR}${PREFIX}/share/games/fortune/stephehchow
	${STRCMD} ${STAGEDIR}${PREFIX}/share/games/fortune/tangshi
	${STRCMD} ${STAGEDIR}${PREFIX}/share/games/fortune/xiaoxing
	${STRCMD} ${STAGEDIR}${PREFIX}/share/games/fortune/yijing

.include <bsd.port.mk>
