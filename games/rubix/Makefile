# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	rubix
PORTVERSION=	1.0.6
CATEGORIES=	games
MASTER_SITES=	http://sed.free.fr/rubix/ \
		http://mirror.mcx2.org/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Another Rubik's cube game with a rather interesting interface

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DENGLISH" \
		XINC="-I${LOCALBASE}/include" XLIB="-L${LOCALBASE}/lib -lX11"
ALL_TARGET=	${PORTNAME}
USE_GCC=	any

PORTDOCS=	${DOCFILES}
PLIST_FILES=	bin/rubix

DOCFILES=	AUTHORS BUGS INSTALL README TODO

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rubix ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
