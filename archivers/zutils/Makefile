PORTNAME=	zutils
PORTVERSION=	1.11
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH/zutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities for searching in bzip2, gzip, lzip, and xz archives

LICENSE=	GPLv2

USES=		cpe tar:lz
GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	gzip # bin/zcat bin/zcmp bin/zdiff bin/zgrep man/man1/ztest.1.gz

INSTALL_TARGET=	install-strip
CPE_VENDOR=	nongnu

INFO=		zutils

post-patch:
	# Remove compiler hardcoded flags and use environment
	@${REINPLACE_CMD} '23,26d' ${WRKSRC}/configure

post-install:
	@-${RM} ${STAGEDIR}${PREFIX}/info/dir

.include <bsd.port.mk>
