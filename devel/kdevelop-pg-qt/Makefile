# Created by: Douglas Carmichael <dcarmich@dcarmichael.net>
# $FreeBSD$

PORTNAME=	kdevelop-pg-qt
PORTVERSION=	1.0.0
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Parser-generator from KDevplatform

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex

USES=		bison cmake:outsource compiler:c++11-lib tar:bzip2
USE_KDE4=	automoc4 kdelibs kdeprefix
USE_QT4=	qmake_build moc_build uic_build rcc_build

.include <bsd.port.mk>
