PORTNAME=	envsubst
PORTVERSION=	0.1

CATEGORIES=	devel
MASTER_SITES=	https://distfiles.dereferenced.org/envsubst/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Perform variable substitutions on input

LICENSE=	ISCL

USES=		tar:xz
USE_CSTD=	c99

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/isc-${PORTNAME}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/isc-${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/isc-${PORTNAME}

.include <bsd.port.mk>
