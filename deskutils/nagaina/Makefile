# New ports collection makefile for:	nagaina
# Date created:		21 August 2007
# Whom:			Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	nagaina
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}-sources

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A notes-taking application based QT4

USE_QT_VER=	4
QT_COMPONENTS=	gui xml qmake_build moc_build rcc_build uic_build
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} share/pixmaps/${PORTNAME}.png
PORTDOCS=	CHANGELOG COMPILE LICENSE TODO

DESKTOP_ENTRIES=	"${PORTNAME}" \
			"${COMMENT}" \
			"${PORTNAME}" \
			"${PORTNAME}" \
			"Qt;KDE;Office;Utility;" \
			"false"

pre-build:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE}

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/images/${PORTNAME}.png ${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
