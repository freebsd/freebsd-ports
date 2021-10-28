PORTNAME=	gperf
PORTVERSION=	3.1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Generates perfect hash functions for sets of keywords

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	ace+tao
MAKE_JOBS_UNSAFE=	yes

USES=		cpe
CPE_VENDOR=	${CPE_PRODUCT}_project
CPE_PRODUCT=	${PORTNAME}tools
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
INFO=		gperf
TEST_TARGET=	check

.include <bsd.port.mk>
