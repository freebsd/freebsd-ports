# Created by: Jason Bacon <bacon11@tds.net>
# $FreeBSD$

PORTNAME=	libnxt
PORTVERSION=	0.3
CATEGORIES=	devel
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/libnxt/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Lego NXT library

SUB_FILES=	pkg-message
USES=		python:2.7,build scons shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	make_flash_header.py

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/libnxt
	${INSTALL_PROGRAM} ${WRKSRC}/fwflash ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fwexec ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libnxt.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/libnxt
.for file in ${WRKSRC}/*.h
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/include/libnxt
.endfor

.include <bsd.port.mk>
