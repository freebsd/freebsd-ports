# Created by: ABURAYER Rewsirow <pcs51674@asciinet.or.jp>
# $FreeBSD$

PORTNAME=	uudx
PORTVERSION=	2.99
CATEGORIES=	converters
MASTER_SITES=	http://ftp.vector.co.jp/01/45/528/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extractor from uuencoded files

BUILD_DEPENDS=	nkf:japanese/nkf

USES=		dos2unix lha
DOS2UNIX_FILES=	uudx.1 uudx.c
NO_WRKSUBDIR=	yes
MAKEFILE=	${FILESDIR}/Makefile
PLIST_FILES=	bin/uudx \
		man/ja/man1/uudx.1.gz

.include <bsd.port.mk>
