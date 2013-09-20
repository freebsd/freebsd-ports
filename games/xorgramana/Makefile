# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorgramana
PORTVERSION=	0.0.8
PORTREVISION=	7
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

ALL_TARGET=	${PORTNAME}
MKE_JOBS_SAFE=	yes

PORTDOCS=	README
PORTDATA=	*

PLIST_FILES=	bin/${PORTNAME}

DESKTOP_ENTRIES="XorGramana" \
		"Logic word puzzle game set inside a series of mazes" \
		"${DATADIR}/GFX/x.png" \
		"xorgramana" \
		"Game;LogicGame;" \
		false

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|GFX/|${DATADIR}/&|' ${WRKSRC}/icons.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "data GFX" ${DATADIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
