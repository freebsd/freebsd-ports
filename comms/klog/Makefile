# $FreeBSD$

PORTNAME=	klog
PORTVERSION=	0.9.2.1
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	SAVANNAH

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Simple Qt-based amateur radio logger

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		qmake
USE_QT4=	corelib gui network sql sql-sqlite3_run moc_build
DESKTOP_ENTRIES=	"KLog" "Simple Amateur Radio Logging Program" \
		"" "klog" "Network;HamRadio;" \
		true

PLIST_FILES=	bin/klog \
		${DATADIR}/translations/klog_es.qm \
		${DATADIR}/translations/klog_fr.qm \
		man/man1/klog.1.gz

post-patch:
	@${REINPLACE_CMD} '/"klog_" + QLocale::system().name()/\
		s|);|, "${DATADIR}/translations/");|' \
			${WRKSRC}/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/klog ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/klog_*.qm ${STAGEDIR}${DATADIR}/translations
	${INSTALL_MAN} ${WRKSRC}/klog.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
