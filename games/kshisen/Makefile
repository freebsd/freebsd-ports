# $FreeBSD$

PORTNAME=	kshisen
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	games kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

LIB_DEPENDS=	libkmahjongglib.so:games/libkmahjongg

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs libkdegames automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build

.include <${.CURDIR}/../kdegames4/Makefile.common>
.include <bsd.port.mk>
