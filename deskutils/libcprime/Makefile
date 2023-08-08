PORTNAME=	libcprime
DISTVERSION=	4.3.0
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Library for bookmarking, saving recent activites, managing settings
WWW=		https://gitlab.com/cubocore/libcprime

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake qt:5
USE_QT=		buildtools:build core dbus gui network qmake:build widgets
USE_LDCONFIG=	yes
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_TAGNAME=	dc9533013e577582193506a154c967bdc63207d3

.include <bsd.port.mk>
