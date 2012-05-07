# Ports collection Makefile for:	cutemaze
# Date created:				20 April 2012
# Whom:					nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	cutemaze
PORTVERSION=	1.1.0
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Is a simple, top-down game in which mazes are randomly generated

LICENSE=	GPLv3

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
MAKE_JOBS_SAFE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build iconengines imageformats
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	UIC="${UIC}" QMAKE="${QMAKE}" QMAKESPEC="${QMAKESPEC}"
MAKE_ENV+=	QMAKESPEC="${QMAKESPEC}"

PORTDATA=	*
PORTDOCS=	ChangeLog README
INSTALLS_ICONS=	yes

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} PREFIX=${PREFIX} ${WRKSRC}/${PORTNAME}.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/icons/oxygen
.for d in icons
	(cd ${WRKSRC}/${d} && ${COPYTREE_SHARE} oxygen ${PREFIX}/share/icons/)
.endfor
	${INSTALL_DATA} ${WRKSRC}/icons/${PORTNAME}.png ${PREFIX}/share/pixmaps/
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/${PORTNAME}.desktop \
		${PREFIX}/share/applications/
.if !defined (NOPORTDATA)
	${MKDIR} ${DATADIR}
.  for d in preview themes
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.  endfor
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
