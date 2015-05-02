# $FreeBSD$

PORTNAME=	klog
PORTVERSION=	0.9.1.1
CATEGORIES=	comms hamradio
MASTER_SITES=		SAVANNAH

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Simple Qt-based amateur radio logger

USES=		qmake
USE_QT4=	gui network sql corelib linguist moc_build
DESKTOP_ENTRIES=	"KLog" "Simple Amateur Radio Logging Program" \
		"" "klog" "Network;HamRadio;" \
		true

PLIST_FILES=	bin/klog \
		man/man1/klog.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/klog ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/klog.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
