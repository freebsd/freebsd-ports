# Created by: Jason Bacon <bacon11@tds.net>
# $FreeBSD$

PORTNAME=	libnxt
PORTVERSION=	0.3
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Lego NXT library

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons

SUB_FILES=	pkg-message
USES=		python:build shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	make_flash_header.py

do-build:
	(cd ${WRKSRC}; scons)

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
