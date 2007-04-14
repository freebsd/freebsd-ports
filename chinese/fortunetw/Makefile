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

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A very classic fortune file in Taiwan

NO_BUILD=	yes

STRCMD=		/usr/games/strfile

do-install:
	@${MKDIR} ${TARGETDIR}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/bsdchat ${TARGETDIR}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/folksong ${TARGETDIR}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/liuyong ${TARGETDIR}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/stephehchow ${TARGETDIR}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/tangshi ${TARGETDIR}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/xiaoxing ${TARGETDIR}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/yijing ${TARGETDIR}/share/games/fortune

pre-install:
.if !exists(${STRCMD})
	@${ECHO_MSG}	"Please install the games distribution"
	@exit 1
.endif

post-install:
	@${STRCMD} ${TARGETDIR}/share/games/fortune/bsdchat
	@${STRCMD} ${TARGETDIR}/share/games/fortune/folksong
	@${STRCMD} ${TARGETDIR}/share/games/fortune/liuyong
	@${STRCMD} ${TARGETDIR}/share/games/fortune/stephehchow
	@${STRCMD} ${TARGETDIR}/share/games/fortune/tangshi
	@${STRCMD} ${TARGETDIR}/share/games/fortune/xiaoxing
	@${STRCMD} ${TARGETDIR}/share/games/fortune/yijing
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Usage:"
	@${ECHO_MSG} "${STRCMD} ${TARGETDIR}/share/games/fortune/bsdchat"
	@${ECHO_MSG} "${STRCMD} ${TARGETDIR}/share/games/fortune/folksong"
	@${ECHO_MSG} "${STRCMD} ${TARGETDIR}/share/games/fortune/liuyong"
	@${ECHO_MSG} "${STRCMD} ${TARGETDIR}/share/games/fortune/stephehchow"
	@${ECHO_MSG} "${STRCMD} ${TARGETDIR}/share/games/fortune/tangshi"
	@${ECHO_MSG} "${STRCMD} ${TARGETDIR}/share/games/fortune/xiaoxing"
	@${ECHO_MSG} "${STRCMD} ${TARGETDIR}/share/games/fortune/yijing"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
