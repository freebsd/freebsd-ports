# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	3dc
PORTVERSION=	0.8.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/strategy
DISTNAME=	3Dc-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3-Dimensional Chess for X Window System

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../GPL

LIB_DEPENDS=	libXaw3d.so:x11-toolkits/Xaw3d

USES=		perl5
USE_PERL5=	build
USE_XORG=	x11 xaw xext xmu xpm xt
WRKSRC=		${WRKDIR}/3Dc/src
DOCSDIR=	${PREFIX}/share/doc/3Dc

OPTIONS_DEFINE=	DOCS

post-patch:
.for file in init.c main.c piece.c stack.c xif.c
	@${REINPLACE_CMD} -i '' -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/3Dc ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in 3Dc-rules.html ACKNOWLEDGEMENTS GPL README TODO
	${INSTALL_DATA} ${WRKSRC}/../${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
