PORTNAME=	rzip
DISTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	SAMBA/rzip

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Compression program similar to gzip or bzip2
WWW=		https://rzip.samba.org/

LICENSE=	GPLv2

USES=		cpe

CPE_VENDOR=	rzip_project

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${STAGEDIR}${PREFIX}

PLIST_FILES=	bin/rzip \
		share/man/man1/rzip.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rzip

.include <bsd.port.mk>
