# New ports collection makefile for:	zh-tw-links
# Date created:				December 27 2002
# Whom:					Eric Shao-yu Cheng
#                                       <eric@fractal.csie.org>
#
# $FreeBSD$
#

CATEGORIES=     chinese www

MAINTAINER=     eric@fractal.csie.org
COMMENT=	Links WWW browser with Chinese language support

MASTERDIR=	${.CURDIR}/../../www/links
EXTRA_PATCHES=	${.CURDIR}/files/patch-codepage.inc \
		${.CURDIR}/files/patch-charsets.c \
		${.CURDIR}/files/patch-html_r.c \
		${.CURDIR}/files/patch-intl-chinese_big5.lng \
		${.CURDIR}/files/patch-intl-index.txt \
		${.CURDIR}/files/patch-language.inc \
		${.CURDIR}/files/patch-links.h

pre-configure:
	cd ${WRKSRC}/intl && ./synclang

.include "${.CURDIR}/../Makefile.inc"
PKGNAMEPREFIX:= ${PKGNAMEPREFIX}tw-

.include "${MASTERDIR}/Makefile"
