PORTNAME=		cutecom
DISTVERSION=		0.51.0
PORTREVISION=	1
CATEGORIES=		comms

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Graphical serial terminal for embedded programming
WWW=		https://gitlab.com/cutecom/cutecom

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	lsz:comms/lrzsz

USES=		cmake compiler:c++11-lang qt:5
USE_QT=		buildtools:build core gui network qmake:build serialport widgets
USE_GITLAB=	yes

GL_TAGNAME=	cce2e5ec01df09ca4b05f055f21942e0de7eb7dd

PLIST_FILES=	bin/cutecom

.include <bsd.port.mk>
