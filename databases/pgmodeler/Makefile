PORTNAME=	pgmodeler
PORTVERSION=	1.1.6
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	PostgreSQL Database Modeler
WWW=		http://pgmodeler.com.br/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lib gl gmake gnome pgsql pkgconfig qmake qt:6 \
		xorg
USE_GITHUB=	yes
USE_GNOME=	libxml2
USE_GL=		gl
USE_QT=		base svg tools
USE_XORG=	x11 xext

USE_LDCONFIG=	yes

QMAKE_SOURCE_PATH=	${WRKSRC}/${PORTNAME}.pro

post-patch:
	@${REINPLACE_CMD} -e 's|linux|unix|g' ${WRKSRC}/${PORTNAME}.pri

.include <bsd.port.mk>
