# New ports collection makefile for: aish
# Version required:	1.12
# Date created:		01 Aug 1998
# Whom:			Masanori Kiriake <seiken@nbs.co.jp>
#
# $FreeBSD$
#

DISTNAME=	aish112
PKGNAME=	aish-1.12
CATEGORIES=	converters
MASTER_SITES=	ftp://ftp.tohoku.ac.jp/pub/unix/aish/
DISTFILES=	aish112u.tar.gz aish112man.tar.gz

MANLANG=	ja
MAN1=		aish.1 autodecode.1
MAKE_ENV=	PATH=/usr/bin:$$PATH

post-extract:
	${MV} ${WRKDIR}/*1 ${WRKSRC}
.include <bsd.port.mk>
