# ex:ts=8
# New ports collection makefile for:	gaim
# Date created:		22 Jan 2002
# Whom:			CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	korean net

MASTERDIR=	${.CURDIR}/../../net/gaim

MAINTAINER=	cjh@FreeBSD.org

LIB_DEPENDS+=	iconv.3:${PORTSDIR}/converters/libiconv

# Slightly modified from http://master.debian.or.kr/~alee/patch/
EXTRA_PATCHES=	${.CURDIR}/files/gaim-utf.diff

.if !exists(/usr/include/langinfo.h)
BROKEN=		"/usr/include/langinfo.h needed; 4-stable after Mar 13 2002 and -current"
.endif

.include "${MASTERDIR}/Makefile"
