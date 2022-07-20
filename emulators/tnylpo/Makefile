PORTNAME=	tnylpo
DISTVERSION=	1.1.3
CATEGORIES=	emulators
MASTER_SITES=	https://gitlab.com/gbrein/${PORTNAME}/-/archive/${DISTVERSION}/

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	CP/M emulator

LICENSE=	BSD3CLAUSE

USES=		tar:bzip2 gmake

MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tnylpo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tnylpo-convert ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tnylpo.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/tnylpo-convert.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/mine/mine.com \
		${STAGEDIR}${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/mine/README.md \
		${STAGEDIR}${PREFIX}/share/${PORTNAME}

.include <bsd.port.mk>
