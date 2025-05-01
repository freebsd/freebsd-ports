PORTNAME=	gperf
PORTVERSION=	3.2.1
PORTREVISION=	1
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
USE_CSTD=	gnu99
USE_CXXSTD=	gnu++98

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
MAKE_JOBS_UNSAFE=	yes
WITH_TESTING=	yes
TEST_TARGET=	check

INFO=		gperf

.include <bsd.port.mk>
