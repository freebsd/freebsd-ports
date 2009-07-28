# New ports collection makefile for:	pipepanic
# Date created:		20 May 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	pipepanic
PORTVERSION=	0.1.3
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.users.waitrose.com/~thunor/pipepanic/dload/ \
		${MASTER_SITE_LOCAL} \
		http://mirror.amdmi3.ru/distfiles/
MASTER_SITE_SUBDIR=	ehaupt
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A pipe connecting game using libSDL

USE_SDL=	sdl

PORTDOCS=	README
DATAFILES=	ascii15.bmp ascii30.bmp digits24.bmp \
		digits48.bmp tiles24.bmp tiles48.bmp

post-patch:
	@${REINPLACE_CMD} \
		-e '/^#define DATADIR/ s|.*|#define DATADIR "${DATADIR}/"|' \
			${WRKSRC}/main.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for f in ${DATAFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
