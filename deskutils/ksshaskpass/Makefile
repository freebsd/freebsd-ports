# New ports collection makefile for:	ksshaskpass
# Date created:		2010-12-26
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ksshaskpass
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
DISTNAME=	50971-${PORTNAME}-${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	A KDE 4 version of ssh-askpass with KWallet support

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_CMAKE=	yes
USE_KDE4=	kdelibs automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qmake moc_build uic_build qmake_build rcc_build

MAN1=		ksshaskpass.1
SUB_FILES=	pkg-message

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
