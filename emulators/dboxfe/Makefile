# $FreeBSD$

PORTNAME=	dboxfe
PORTVERSION=	0.1.3
PORTREVISION=	7
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt4 based configuration manager for DOSBox

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

RUN_DEPENDS=	dosbox:emulators/dosbox

USES=		qmake qt:4 tar:bzip2
USE_QT=		corelib gui network xml uic_build moc_build qmake_build rcc_build

PLIST_FILES=	bin/dboxfe \
		bin/dboxfetray \
		share/pixmaps/dboxfe.png

DESKTOP_ENTRIES="DBoxFE" "DOSBox configuration manager" \
		"${PREFIX}/share/pixmaps/dboxfe.png" \
		"dboxfe" "Utility;Qt;" true \
		"DBoxFEtray" "DBoxFE systray icon" \
		"${PREFIX}/share/pixmaps/dboxfe.png" \
		"dboxfetray" "Utility;Qt;TrayIcon;" true

post-build:
	@(cd ${WRKSRC}/dboxfetray && \
		${SETENV} ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS} && \
		${SETENV} ${MAKE_ENV} ${MAKE})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dboxfe ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dboxfetray ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dboxfetray/res/dboxfetray.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/dboxfe.png

.include <bsd.port.mk>
