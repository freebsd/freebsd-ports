# New ports collection makefile for:	zh-dia
# Date created:			6 March 2001
# Whom:				Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	chinese

MASTERDIR=	${.CURDIR}/../../graphics/dia

PATCH_SITES=	http://www.sinica.edu.tw/~jihuang/
PATCHFILES=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}-big5.diff.gz

MD5_FILE=	${.CURDIR}/distinfo

# For png output
USE_GNOMENG=	yes
USE_GNOME+=	gnomelibs

.include "${MASTERDIR}/Makefile"
MAINTAINER=	keith@FreeBSD.org

