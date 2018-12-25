# Created by: Douglas Carmichael <dcarmich@dcarmichael.net>
# $FreeBSD$

PORTNAME=	kdevelop-pg-qt
DISTVERSION=	1.0.0
PORTREVISION=	7
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Parser-generator from KDevplatform

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex

USES=		bison cmake compiler:c++11-lib kde:4 qt:4 tar:bzip2
USE_KDE=	automoc4 kdelibs
USE_QT=		qmake_build moc_build uic_build rcc_build

.include <bsd.port.mk>
