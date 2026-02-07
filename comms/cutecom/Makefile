PORTNAME=		cutecom
DISTVERSION=		0.60.0
DISTVERSIONSUFFIX=	-RC1
CATEGORIES=		comms

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Graphical serial terminal for embedded programming
WWW=		https://gitlab.com/cutecom/cutecom

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	lsz:comms/lrzsz

USES=		desktop-file-utils cmake compiler:c++11-lang gl qt:6
USE_GL=		gl
USE_QT=		base serialport tools:build
USE_GITLAB=	yes

GL_TAGNAME=	v0.60.0-RC1

.include <bsd.port.mk>
