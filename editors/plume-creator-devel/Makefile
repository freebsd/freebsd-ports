# $FreeBSD$

PORTNAME=	plume-creator-devel
PORTVERSION=	${DATE}
CATEGORIES=	editors
MASTER_SITES=	http://deponie.yamagi.org/freebsd/distfiles/plume-creator/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source tool for novelists

LICENSE=	GPLv3+

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

DATE=		20150510

USES=		desktop-file-utils qmake qt:4 shared-mime-info tar:xz
USE_QT=		corelib gui moc_build qmake_build rcc_build uic_build webkit
QMAKE_ARGS=	${WRKSRC}/plume-creator.pro

.include <bsd.port.mk>
