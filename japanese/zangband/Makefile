# New ports collection makefile for:	ja-zangband
# Date Created:			31 May 2000
# Whom:				Makoto YAMAKURA <makoto@pinpott.spnet.ne.jp>
#
# $FreeBSD$
#

CATEGORIES=	japanese

MAINTAINER=	makoto@pinpott.spnet.ne.jp

MASTERDIR=	${.CURDIR}/../../games/zangband

PKGDIR=		${MASTERDIR}/pkg
COMMENT=	${.CURDIR}/pkg/COMMENT
DESCR=		${.CURDIR}/pkg/DESCR

JAPANESE=	yes
JA_MASTER_SITE=	http://www.geocities.co.jp/SiliconValley-SanJose/9606/zg/
ANGBANDLIB?= 	lib/jzangband
ANGBANDBIN?= 	bin/jzangband
JA_PLIST= 	PLIST.ja
MAKE_ARGS+=	JAPANESE_CFLAGS="-DJP -DEUC"

.include "${MASTERDIR}/Makefile"
