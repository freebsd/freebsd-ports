# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ksshaskpass
PORTVERSION=	0.5.3
PORTREVISION=	7
CATEGORIES=	deskutils
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
DISTNAME=	50971-${PORTNAME}-${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	KDE 4 version of ssh-askpass with KWallet support

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		cmake kde:4 qt:4
USE_KDE=	kdelibs automoc4
USE_QT=		moc_build uic_build qmake_build rcc_build

SUB_FILES=	pkg-message

.include <bsd.port.mk>
