# $FreeBSD$

PORTNAME=	ksirk
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	5
CATEGORIES=	games kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libqca.so:devel/qca@qt4

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs libkdegames automoc4
USE_QT=		corelib gui corelib gui network qt3support svg xml \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <${.CURDIR}/../kdegames-kde4/Makefile.common>
.include <bsd.port.mk>
