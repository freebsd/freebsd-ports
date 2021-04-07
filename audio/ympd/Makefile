PORTNAME=	ympd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	audio www

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Stand-alone lightweight web UI controller for audio/musicpd

LICENSE=	GPLv2 BSD3CLAUSE MIT
LICENSE_COMB=	multi

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient

USES=		cmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=	notandy

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
