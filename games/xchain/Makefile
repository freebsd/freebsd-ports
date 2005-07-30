# New ports collection makefile for:	xchain
# Date created:				13 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xchain
PORTVERSION=	1.0.2
CATEGORIES=	games
MASTER_SITES=	# no longer available
DISTNAME=	${PORTNAME}_1.0-2

DEPRECATED=	"master site disappeared, Debian archive has 1.0.1"
EXPIRATION_DATE=2005-08-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chain Reaction, a strategy game for 2-4 players

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/${PORTNAME}-1.0
MAKE_ARGS=	CC="${CC}" CFLAGS='${CFLAGS} -DDEF_WISH_PATH=\"${LOCALBASE}/bin/wish8.2\"'

USE_X_PREFIX=	yes
MAN6=		xchain.6
PLIST_FILES=	bin/xchain
PORTDOCS=	README copyright

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xchain ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xchain.6 ${PREFIX}/man/man6
	@${MKDIR} ${PREFIX}/share/doc/xchain
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xchain
	${INSTALL_DATA} ${WRKSRC}/copyright ${PREFIX}/share/doc/xchain

.include <bsd.port.mk>
