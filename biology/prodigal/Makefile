# $FreeBSD$

PORTNAME=	prodigal
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.3-7
DISTVERSIONSUFFIX=	-ga78ed3f
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Protein-coding gene prediction for prokaryotic genomes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	hyattpd
GH_PROJECT=	Prodigal

BINARY_ALIAS=	gcc=${CC}
MAKE_ARGS=	INSTALLDIR=${STAGEDIR}${PREFIX}/bin

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
