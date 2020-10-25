# $FreeBSD$

PORTNAME=	yuck
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.5-6
DISTVERSIONSUFFIX=	-gb4f9441
CATEGORIES=	devel
PKGNAMESUFFIX=	-cmdline-parser

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bog-standard command line option parser for C

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		autoreconf gmake

USE_GITHUB=	yes
GH_ACCOUNT=	hroptatyr

GNU_CONFIGURE=	yes

post-install:
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
