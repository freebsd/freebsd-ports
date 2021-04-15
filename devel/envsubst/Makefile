PORTNAME=	envsubst
PORTVERSION=	0.1

CATEGORIES=	devel
MASTER_SITES=	https://distfiles.dereferenced.org/envsubst/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	perform variable substitutions on input

USES=	tar:xz
LICENSE=	ISCL

PLIST_FILES=	bin/isc-${PORTNAME}

ALL_TARGET=	${PORTNAME}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/isc-${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/isc-${PORTNAME}

.include <bsd.port.mk>

