# ex:ts=8
# New ports collection makefile for:	gaim
# Date created:		22 Jan 2002
# Whom:			CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	korean net

PATCH_SITES=	http://master.debian.or.kr/~alee/patch/ \
		ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/
PATCHFILES=	gaim-0.59-i18n-2.diff.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	cjh@FreeBSD.org

BROKEN=		"Broken by master port update"

LIB_DEPENDS+=	iconv.3:${PORTSDIR}/converters/libiconv

MASTERDIR=	${.CURDIR}/../../net/gaim
MD5_FILE=	${.CURDIR}/distinfo

.if !exists(/usr/include/langinfo.h)
BROKEN=		"/usr/include/langinfo.h needed; 4-stable after Mar 13 2002 and -current"
.endif

.include "${MASTERDIR}/Makefile"
