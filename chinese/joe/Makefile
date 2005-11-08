# New ports collection makefile for:	zh-joe
# Date created:			3 July 1999
# Whom:				Shen Chuan-Hsing <statue@mail.elife.idv.tw>
#
# $FreeBSD$
#

CATEGORIES=	chinese editors

PATCH_SITES=	http://opensvn.csie.org/chinsan/patch/ \
		ftp://bbs.ilc.edu.tw/chinsan/patch/ \
		http://bbs.ilc.edu.tw/~chinsan/ports/joe2/ \
		ftp://news.giga.net.tw/chinsan/patch/
PATCHFILES=	zh-joe-2.9.8.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	chinsan.tw@gmail.com

LATEST_LINK=	${PKGNAMEPREFIX}joe

MASTERDIR=	${.CURDIR}/../../editors/joe
MD5_FILE=	${.CURDIR}/distinfo

IGNORE=	"Waiting to be updated to 3.x, use chinese/joe2"

.include "${MASTERDIR}/Makefile"
