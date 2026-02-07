PORTNAME=	basu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
CATEGORIES=	devel
MASTER_SITES=	https://git.sr.ht/~emersion/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	sd-bus library, extracted from systemd
WWW=		https://sr.ht/~emersion/basu/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL2.1

USES=		compiler:c11 gperf meson python:build shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	src/basic/generate-gperfs.py
MESON_DISABLED=	audit libcap

.include <bsd.port.mk>
