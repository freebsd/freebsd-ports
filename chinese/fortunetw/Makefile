# New ports collection makefile for:   fortunetw
# Date created:                10 Mar 2001
# Whom:                        Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	fortunetw
PORTVERSION=	1.3
CATEGORIES=	chinese
MASTER_SITES=	LOCAL/chinsan \
		http://chinsan2.twbbs.org/distfiles/
DISTNAME=	zh-fortunetw-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A very classic fortune file in Taiwan

NO_BUILD=	yes

STRCMD=		/usr/games/strfile

do-install:
	@${MKDIR} ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/bsdchat ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/folksong ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/liuyong ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/stephehchow ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/tangshi ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/xiaoxing ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/yijing ${PREFIX}/share/games/fortune

pre-install:
.if !exists(${STRCMD})
	@${ECHO_MSG}	"Please install the games distribution"
	@exit 1
.endif

post-install:
	@${STRCMD} ${PREFIX}/share/games/fortune/bsdchat
	@${STRCMD} ${PREFIX}/share/games/fortune/folksong
	@${STRCMD} ${PREFIX}/share/games/fortune/liuyong
	@${STRCMD} ${PREFIX}/share/games/fortune/stephehchow
	@${STRCMD} ${PREFIX}/share/games/fortune/tangshi
	@${STRCMD} ${PREFIX}/share/games/fortune/xiaoxing
	@${STRCMD} ${PREFIX}/share/games/fortune/yijing
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Usage:"
	@${ECHO_MSG} "${STRCMD} ${PREFIX}/share/games/fortune/bsdchat"
	@${ECHO_MSG} "${STRCMD} ${PREFIX}/share/games/fortune/folksong"
	@${ECHO_MSG} "${STRCMD} ${PREFIX}/share/games/fortune/liuyong"
	@${ECHO_MSG} "${STRCMD} ${PREFIX}/share/games/fortune/stephehchow"
	@${ECHO_MSG} "${STRCMD} ${PREFIX}/share/games/fortune/tangshi"
	@${ECHO_MSG} "${STRCMD} ${PREFIX}/share/games/fortune/xiaoxing"
	@${ECHO_MSG} "${STRCMD} ${PREFIX}/share/games/fortune/yijing"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
