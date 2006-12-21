# New ports collection Makefile for:	stroq
# Date created:				13 Jan 2005
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$

PORTNAME=	stroq
PORTVERSION=	0.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	stroq

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Flip tiles to make rows of the same color

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_BZIP2=	yes
USE_QT_VER=	3
MAKE_ENV=	QTDIR="${QT_PREFIX}"

QMAKE=		qmake
QMAKESPEC=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD 4.x
.endif

post-patch:
	${REINPLACE_CMD} -e 's|PlaySquare::||' ${WRKSRC}/playsquare.h
	${REINPLACE_CMD} -e 's|Puzzle::||' ${WRKSRC}/puzzle.h
	${REINPLACE_CMD} -e 's|Square::||' ${WRKSRC}/square.h
	${REINPLACE_CMD} -e 's|SelectPuzzleDialog::||' ${WRKSRC}/selectpuzzledialog.h

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${QMAKE} -project; \
	${SETENV} ${MAKE_ENV} QMAKESPEC=${QMAKESPEC} ${QMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-${PORTVERSION} ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
