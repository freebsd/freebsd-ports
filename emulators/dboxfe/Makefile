# $FreeBSD$

PORTNAME=	dboxfe
PORTVERSION=	0.1.3
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt4 based configuration manager for DOSBox

RUN_DEPENDS=	dosbox:${PORTSDIR}/emulators/dosbox

USE_BZIP2=	yes
USE_QT4=	gui network xml uic_build moc_build qmake_build rcc_build
HAS_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/dboxfe \
		bin/dboxfetray \
		share/pixmaps/dboxfe.png

DESKTOP_ENTRIES=	"DBoxFE" "DOSBox configuration manager" \
		"${PREFIX}/share/pixmaps/dboxfe.png" \
		"dboxfe" "Utility;Qt;" false \
		"DBoxFEtray" "DBoxFE systray icon" \
		"${PREFIX}/share/pixmaps/dboxfe.png" \
		"dboxfetray" "Utility;Qt;TrayIcon;" false

PRO_DIRS=	. dboxfetray

do-configure:
.for dir in ${PRO_DIRS}
	@(cd ${WRKSRC}/${dir} && \
		${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS})
.endfor

do-build:
.for dir in ${PRO_DIRS}
	@(cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${MAKE})
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dboxfe ${PREFIX}/bin/dboxfe
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dboxfetray ${PREFIX}/bin/dboxfetray
	${INSTALL_DATA} ${WRKSRC}/dboxfetray/res/dboxfetray.png \
		${PREFIX}/share/pixmaps/dboxfe.png

.include <bsd.port.mk>
