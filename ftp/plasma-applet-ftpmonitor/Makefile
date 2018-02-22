# $FreeBSD$

PORTNAME=	ftpmonitor
PORTVERSION=	1.1
PORTREVISION=	8
CATEGORIES=	ftp kde
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/ftpmonitor/
PKGNAMEPREFIX=	plasma-applet-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE4 Plasma applet, which monitors connections to ftp daemons

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake kde:4 tar:bzip2
USE_KDE=	kdelibs automoc4
USE_QT4=	qmake_build moc_build uic_build rcc_build

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/src/ftpserver/*.h

.include <bsd.port.mk>
