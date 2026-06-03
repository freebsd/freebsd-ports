PORTNAME=	gperf
DISTVERSION=	3.3
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Generates perfect hash functions for sets of keywords
WWW=		https://www.gnu.org/software/gperf/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe
CPE_VENDOR=	${CPE_PRODUCT}_project
CPE_PRODUCT=	${PORTNAME}tools

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR}

MAKE_JOBS_UNSAFE=	yes
INFO=		gperf

TEST_TARGET=	check

.include <bsd.port.mk>
