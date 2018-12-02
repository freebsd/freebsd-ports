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

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 qt:4 tar:bzip2
USE_KDE=	kdelibs automoc4
USE_QT=		qmake_build moc_build uic_build rcc_build

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/src/ftpserver/*.h

.include <bsd.port.mk>
