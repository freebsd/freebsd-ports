# New ports collection makefile for:	xorgramana
# Date created:		27 Mar 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xorgramana
PORTVERSION=	0.0.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.jwm-art.net/XorGramana/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	XorGramana-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Logic word puzzle game set inside a series of mazes

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl image
USE_GL=		glu
MAKE_JOBS_SAFE=	yes

ALL_TARGET=	${PORTNAME}
MKE_JOBS_SAFE=	yes

PORTDOCS=	README

DESKTOP_ENTRIES="XorGramana" \
		"Logic word puzzle game set inside a series of mazes" \
		"${DATADIR}/GFX/x.png" \
		"xorgramana" \
		"Game;LogicGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e 's|GFX/|${DATADIR}/&|' ${WRKSRC}/icons.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "data GFX" ${DATADIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
