# $FreeBSD$

PORTNAME=	trimadap
DISTVERSION=	0.1-3
DISTVERSIONSUFFIX=	-gddfef21
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Trim adapter sequences from Illumina data using heuristic rules

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	lh3

PLIST_FILES=	bin/trimadap-mt

CFLAGS_i386=	-msse2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trimadap-mt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
