# New ports collection makefile for:	ruby-usersguide-jp
# Date created:			30 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../../lang/ruby-usersguide

MASTER_SITES=	ftp://ftp.netlab.co.jp/pub/lang/ruby/doc/

CATEGORIES=	japanese

MAINTAINER=	knu@FreeBSD.org

VERSION=	980206

FILESDIR=	${.CURDIR}/files
PKGDIR=		${.CURDIR}/pkg

LANGSUFFIX=	-jp

pre-install:
	${LN} -sf uguide00.html ${WRKSRC}/index.html

.include "${MASTERDIR}/Makefile"
