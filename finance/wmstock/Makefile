# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	wmstock
PORTVERSION=	0.11
PORTREVISION=	4
CATEGORIES=	finance windowmaker
MASTER_SITES=	http://www.mattfischer.com/wmstock/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cool WindowMaker Dockapp that shows stock ticker(s)

USES=		gmake shebangfix xorg
USE_XORG=	xpm
SHEBANG_FILES=	getquote

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

WRKSRC=		${WRKDIR}/wmstock/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmstock ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/getquote ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmstock.1x ${STAGEDIR}${PREFIX}/man/man1/wmstock.1

.include <bsd.port.mk>
