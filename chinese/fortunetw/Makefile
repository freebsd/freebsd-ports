# New ports collection makefile for:   fortunetw
# Date created:                10 Mar 2001
# Whom:                        Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	fortunetw
PORTVERSION=	1.1
CATEGORIES=	chinese
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/fortunetw/
DISTNAME=	zh-fortunetw-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A very classic fortune file in Taiwan

NO_BUILD=	yes

STRCMD=		/usr/games/strfile

do-install:
	@${MKDIR} ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/liuyong ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/tangshi ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/yijing ${PREFIX}/share/games/fortune

pre-install:
.if !exists(${STRCMD})
	@${ECHO_MSG}	"Please install the games distribution"
	@exit 1
.endif

post-install:
	@${STRCMD} ${PREFIX}/share/games/fortune/liuyong
	@${STRCMD} ${PREFIX}/share/games/fortune/tangshi
	@${STRCMD} ${PREFIX}/share/games/fortune/yijing
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Usage:"
	@${ECHO_MSG} "/usr/games/fortune ${PREFIX}/share/games/fortune/liuyong"
	@${ECHO_MSG} "or"
	@${ECHO_MSG} "/usr/games/fortune ${PREFIX}/share/games/fortune/tangshi"
	@${ECHO_MSG} "or"
	@${ECHO_MSG} "/usr/games/fortune ${PREFIX}/share/games/fortune/yijing"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
