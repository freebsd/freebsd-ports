PORTNAME=	tnylpo
DISTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	emulators

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	CP/M emulator
WWW=		https://gitlab.com/gbrein/tnylpo

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITLAB=	yes
GL_ACCOUNT=	gbrein
GL_TAGNAME=	3216c00c7a97d373b51192a96da46510f75f1adb

MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tnylpo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tnylpo-convert ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tnylpo.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/tnylpo-convert.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/mine/mine.com \
		${STAGEDIR}${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/mine/README.md \
		${STAGEDIR}${PREFIX}/share/${PORTNAME}

.include <bsd.port.mk>
