# $FreeBSD$

PORTNAME=	samurai
DISTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/michaelforney/samurai/releases/download/${DISTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Ninja-compatible build tool written in C

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

ALL_TARGET=	samu
PLIST_FILES=	bin/samu \
		man/man1/samu.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/samu ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/samu.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
