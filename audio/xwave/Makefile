# Created by: trevor
# $FreeBSD$

PORTNAME=	xwave
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	LOCAL/arved
DISTNAME=	${PORTNAME}${PORTVERSION:S/./v/}

MAINTAINER=	a0516@marimga.de
COMMENT=	Audio player/recorder/editor for the X Window System

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}2-981109
USES=		imake xorg
USE_XORG=	xaw
MAKE_JOBS_UNSAFE=	yes

DOC_FILES=	README README-XWAVE2 README.v06 INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xwave ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/XWave ${STAGEDIR}${PREFIX}/lib/X11/app-defaults
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/xwave
.for i in ${DOC_FILES}
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/share/doc/xwave
.endfor

.include <bsd.port.mk>
