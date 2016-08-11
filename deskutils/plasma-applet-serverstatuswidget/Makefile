# $FreeBSD$

PORTNAME=	serverstatuswidget
PORTVERSION=	1.5.1
PORTREVISION=	6
CATEGORIES=	deskutils kde
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	101336-${PORTNAME}-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE4 server monitoring plasma applet

LICENSE=	GPLv2

USES=		cmake gettext tar:bzip2
USE_KDE4=	automoc4 workspace
USE_QT4=	qmake_build moc_build rcc_build uic_build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	${ECHO_CMD} >> ${WRKSRC}/src/serverstatus.h

.include <bsd.port.mk>
