PORTNAME=	lizard
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
CATEGORIES=	archivers

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Efficient compressor with very fast decompression

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/lib/LICENSE
LICENSE_FILE_GPLv2=	${WRKSRC}/programs/COPYING

USES=		cpe gmake
CPE_VENDOR=	lizard_project

USE_GITHUB=	yes
GH_ACCOUNT=	inikep

USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lizard \
		${STAGEDIR}/${PREFIX}/lib/liblizard.so.1.0.0

.include <bsd.port.mk>
