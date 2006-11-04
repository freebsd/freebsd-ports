# New ports collection makefile for:	ruby_static-devel
# Date created:			3 June 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../ruby16_static

PORTREVISION=	4
PORTEPOCH=	1

RUBY_VER=	1.8

LATEST_LINK=	ruby18_static

pre-build:
	@${RM} ${WRKSRC}/ext/iconv/extconf.rb

.include "${MASTERDIR}/Makefile"
