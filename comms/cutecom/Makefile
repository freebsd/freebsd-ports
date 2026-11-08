PORTNAME=		cutecom
DISTVERSION=		0.60.0
DISTVERSIONSUFFIX=	-RC1
PORTREVISION=		1
CATEGORIES=		comms

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Graphical serial terminal for embedded programming
WWW=		https://gitlab.com/cutecom/cutecom

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	lsz:comms/lrzsz

USES=		cmake compiler:c++17-lang qt:6
USE_QT=		base serialport
USE_GITLAB=	yes

GL_TAGNAME=	v0.60.0-RC1

.include <bsd.port.mk>
