PORTNAME=	libcprime
DISTVERSION=	5.0.1
CATEGORIES=	deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Library for bookmarking, saving recent activites, managing settings
WWW=		https://gitlab.com/cubocore/libcprime

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake gl qt:6
USE_GL=		gl
USE_QT=		base tools:build
USE_LDCONFIG=	yes
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_TAGNAME=	v${DISTVERSION}

.include <bsd.port.mk>
