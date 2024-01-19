PORTNAME=	gperf
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Generates perfect hash functions for sets of keywords
WWW=		https://www.gnu.org/software/gperf/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	ace+tao
MAKE_JOBS_UNSAFE=	yes

USES=		cpe
USE_CSTD=	gnu99
USE_CXXSTD=	gnu++98
CPE_VENDOR=	${CPE_PRODUCT}_project
CPE_PRODUCT=	${PORTNAME}tools
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INFO=		gperf
TEST_TARGET=	check

.include <bsd.port.mk>
