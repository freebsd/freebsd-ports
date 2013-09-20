# Created by: Albert Vernon <f3cun3c02@sneakemail.com>
# $FreeBSD$

PORTNAME=	zutils
PORTVERSION=	1.0
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH/zutils

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Utilities for searching in bzip2, gzip, lzip, and xz archives

LICENSE=	GPLv3

PLIST_FILES=	bin/zcat \
		bin/zcmp \
		bin/zdiff \
		bin/zegrep \
		bin/zfgrep \
		bin/zgrep \
		bin/ztest \
		bin/zutils

MAN1=		zcat.1 \
		zcmp.1 \
		zdiff.1 \
		zgrep.1 \
		ztest.1
INFO=		zutils

NO_STAGE=	yes
GNU_CONFIGURE=	yes

post-patch:
	# Remove compiler hardcoded flags and use environment
	${REINPLACE_CMD} '23,26d' ${WRKSRC}/configure

.include <bsd.port.mk>
