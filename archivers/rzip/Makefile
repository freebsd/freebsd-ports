# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rzip
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	SAMBA/rzip

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Compression program similar to gzip or bzip2

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=${STAGEDIR}${PREFIX}

PLIST_FILES=	bin/rzip man/man1/rzip.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rzip

.include <bsd.port.mk>
