# Created by: jmz

PORTNAME=	iozone
PORTVERSION=	2.01
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/others/
EXTRACT_SUFX=	.shar.gz
PKGNAMESUFFIX=	21

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Performance Test of Sequential File I/O (older version)

CONFLICTS_INSTALL=	iozone

PLIST_FILES=	bin/iozone \
		man/man1/iozone.1.gz

EXTRACT_CMD=	( ${GZCAT} | ${AWK} '{if (/^\#!/) x++} {if(x) print $$0'}| ${SH} )
EXTRACT_BEFORE_ARGS=	<
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=	YES

.include <bsd.port.mk>
