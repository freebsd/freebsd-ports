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

USE_BZIP2=	yes
USE_QT4=	moc_build qmake_build rcc_build uic_build iconengines imageformats
INSTALLS_ICONS=	yes

PORTDOCS=	ChangeLog README

.include <bsd.port.options.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX} ${WRKSRC}/${PORTNAME}.pro

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
