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

LIB_DEPENDS+=	iconv.2:${PORTSDIR}/converters/iconv

# this patch from www.intosea.com
EXTRA_PATCHES=	${.CURDIR}/files/gaim-0.50-ko.patch

.include "${MASTERDIR}/Makefile"
