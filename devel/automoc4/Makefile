# Created by: miwi
# $FreeBSD$

PORTNAME=	automoc4
PORTVERSION=	0.9.88
PORTREVISION=	3
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Automatic moc for Qt 4 packages

USE_QT4=	corelib moc qmake_build rcc_build uic_build
USE_BZIP2=	yes
USES=		cmake iconv
MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
