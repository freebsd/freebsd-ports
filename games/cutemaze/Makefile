# $FreeBSD$

PORTNAME=	cutemaze
PORTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simple, top-down game in which mazes are randomly generated

LICENSE=	GPLv3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		qmake
USE_BZIP2=	yes
USE_QT4=	moc_build rcc_build uic_build iconengines_run imageformats_run
INSTALLS_ICONS=	yes

PORTDOCS=	ChangeLog README

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
# Icons
	@(cd ${WRKSRC}/icons && ${COPYTREE_SHARE} oxygen ${PREFIX}/share/icons/)

# Pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/${PORTNAME}.png ${PREFIX}/share/pixmaps/

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
