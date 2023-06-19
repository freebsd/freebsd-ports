PORTNAME=	qspeakers
DISTVERSION=	1.6.7
CATEGORIES=	cad

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Open source loudspeaker enclosure designer
WWW=		http://brouits.free.fr/qspeakers/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		desktop-file-utils gl pkgconfig qt:5 qmake shared-mime-info
USE_GL=		gl
USE_QT=		charts concurrent core gui linguisttools buildtools:build \
		printsupport widgets xml

USE_GITHUB=	yes
GH_ACCOUNT=	be1

.include <bsd.port.mk>
