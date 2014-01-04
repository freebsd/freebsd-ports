# Created by: jmz
# $FreeBSD$

PORTNAME=	iozone
PORTVERSION=	2.01
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/others/
EXTRACT_SUFX=	.shar.gz
PKGNAMESUFFIX=	21

MAINTAINER=	chifeng@gmail.com
COMMENT=	Performance Test of Sequential File I/O (older version)

CONFLICTS=	iozone-3.*

PLIST_FILES=	bin/iozone

EXTRACT_CMD=	( ${GZCAT} | ${AWK} '{if (/^\#!/) x++} {if(x) print $$0'}| ${SH} )
EXTRACT_BEFORE_ARGS=	<
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=	YES
MAN1=		iozone.1

NO_STAGE=	yes
.include <bsd.port.mk>
