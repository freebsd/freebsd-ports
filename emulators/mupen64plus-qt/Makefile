# $FreeBSD$

PORTNAME=	mupen64plus-qt
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	emulators

MAINTAINER=	maintainer@hasting.email
COMMENT=	Basic launcher for Mupen64Plus

LICENSE=	BSD3CLAUSE

BROKEN=		wrong dependencies, mupen64plus executable is not provided by emulators/mupen64plus
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-05-19

LIB_DEPENDS=	libquazip.so:archivers/quazip@qt4
RUN_DEPENDS=	mupen64plus:emulators/mupen64plus

USES=		qmake
USE_QT4=	corelib gui moc_build network rcc_build sql sql-sqlite3_run uic_build xml

USE_GITHUB=	yes
GH_ACCOUNT=	dh4

PORTDOCS=	README.md

PLIST_FILES=	bin/mupen64plus-qt \
		man/man6/mupen64plus-qt.6.gz \
		share/applications/mupen64plus-qt.desktop \
		share/pixmaps/mupen64plus-qt.png

OPTIONS_DEFINE=		DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/resources/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/resources/images/mupen64plus.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_MAN} ${WRKSRC}/resources/${PORTNAME}.6 ${STAGEDIR}${MANPREFIX}/man/man6

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
