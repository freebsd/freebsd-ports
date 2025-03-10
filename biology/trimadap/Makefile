PORTNAME=	trimadap
DISTVERSION=	0.1-4
DISTVERSIONSUFFIX=	-gec5a764
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Trim adapter sequences from Illumina data using heuristic rules
WWW=		https://github.com/lh3/trimadap

LICENSE=	MIT

BUILD_DEPENDS=	simde>0:devel/simde

USES=		localbase
USE_GITHUB=	yes
GH_ACCOUNT=	lh3

PLIST_FILES=	bin/trimadap-mt

CFLAGS_i386=	-msse2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trimadap-mt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
