# $FreeBSD$

PORTNAME=	plume-creator-devel
PORTVERSION=	${DATE}
CATEGORIES=	editors
MASTER_SITES=	http://deponie.yamagi.org/freebsd/distfiles/plume-creator/

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Plume-Creator is an open-source tool for novelists

LICENSE=	GPLv3 # (or later)

DATE=		20150510

USES=		desktop-file-utils shared-mime-info qmake tar:xz
USE_QT4=	corelib gui moc_build qmake_build rcc_build uic_build webkit
QMAKE_ARGS=	${WRKSRC}/plume-creator.pro

.include <bsd.port.mk>
