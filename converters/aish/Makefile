# New ports collection makefile for:	aish
# Version required:	1.13
# Date created:		01 Aug 1998
# Whom:			Masanori Kiriake <seiken@nbs.co.jp>
#
# $FreeBSD$
#

DISTNAME=	aish113u
PKGNAME=	aish-1.13
CATEGORIES=	converters
MASTER_SITES=	http://hp.vector.co.jp/authors/VA004474/etc/

MAINTAINER=	ports@FreeBSD.org

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ja/aish
	${INSTALL_DATA} ${WRKSRC}/aish.txt ${PREFIX}/share/doc/ja/aish
.endif

.include <bsd.port.mk>
