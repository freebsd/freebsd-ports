# $FreeBSD$

PORTNAME=	plume-creator-devel
PORTVERSION=	${DATE}
CATEGORIES=	editors
MASTER_SITES=	http://deponie.yamagi.org/freebsd/distfiles/plume-creator/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source tool for novelists

LICENSE=	GPLv3+

DATE=		20150510

USES=		desktop-file-utils qmake shared-mime-info tar:xz
USE_QT4=	corelib gui moc_build qmake_build rcc_build uic_build webkit
QMAKE_ARGS=	${WRKSRC}/plume-creator.pro

.include <bsd.port.mk>
