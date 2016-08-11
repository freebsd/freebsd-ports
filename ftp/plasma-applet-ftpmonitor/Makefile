# $FreeBSD$

PORTNAME=	ftpmonitor
PORTVERSION=	1.1
PORTREVISION=	6
CATEGORIES=	ftp kde
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	plasma-applet-

MAINTAINER=	makc@FreeBSD.org
COMMENT=	KDE4 Plasma applet, which monitors connections to ftp daemons

USES=		cmake tar:bzip2
USE_KDE4=	kdelibs automoc4
USE_QT4=	qmake_build moc_build uic_build rcc_build

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/src/ftpserver/*.h

.include <bsd.port.mk>
