# $FreeBSD$

PORTNAME=	dboxfe
PORTVERSION=	0.1.3
PORTREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt4 based configuration manager for DOSBox

RUN_DEPENDS=	dosbox:emulators/dosbox

USE_QT4=	gui network xml uic_build moc_build qmake_build rcc_build
USES=		qmake tar:bzip2

PLIST_FILES=	bin/dboxfe \
		bin/dboxfetray \
		share/pixmaps/dboxfe.png

DESKTOP_ENTRIES=	"DBoxFE" "DOSBox configuration manager" \
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
