PORTNAME=	lizard
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1
CATEGORIES=	archivers

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Efficient compressor with very fast decompression
WWW=		https://github.com/inikep/lizard

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/lib/LICENSE
LICENSE_FILE_GPLv2=	${WRKSRC}/programs/COPYING

USES=		cpe gmake
CPE_VENDOR=	lizard_project

USE_GITHUB=	yes
GH_ACCOUNT=	inikep

USE_LDCONFIG=	yes

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lizard \
		${STAGEDIR}${PREFIX}/lib/liblizard.so.${DISTVERSION}.0

.include <bsd.port.mk>
