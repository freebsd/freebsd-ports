# New ports collection makefile for:	grep+mb
# Version required:	2.0+mb1.04
# Date created:		2 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id: Makefile,v 1.9 1998/08/31 15:37:35 max Exp $
#

DISTNAME=	grep-2.0
PKGNAME=	ja-grep-2.0
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	grep

MAINTAINER=	ports@FreeBSD.ORG

GNU_CONFIGURE=	yes
PATCH_STRIP=	-p1
MAN1=		grep.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja-grep
	${INSTALL_DATA} ${WRKSRC}/README.MB ${PREFIX}/share/doc/ja-grep
.endif

.include <bsd.port.mk>
