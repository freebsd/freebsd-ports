# New ports collection makefile for:    elk
# Version required:     3.0pl2
# Date created:         08 March 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $Id: Makefile,v 1.14 1996/11/18 09:54:13 asami Exp $
#

DISTNAME=	elk-3.0
PKGNAME=	elk-3.0.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.uni-bremen.de/pub/programming/languages/scheme/elk/

MAINTAINER=	tg@freebsd.org

PATCH_STRIP=	-p1
ALL_TARGET=	default
MAN1=		elk.1

#
# we install the scheme binary as ${PREFIX}/bin/elk
# to avoid a clash with mit-scheme.
#

pre-install:
	@${MKDIR} ${PREFIX}/share/elk

post-install:
	@(cd ${PREFIX}/share/elk; \
	  ${CP} bin/scheme ${PREFIX}/bin/elk; \
	  ${MKDIR} ${PREFIX}/include/elk; \
	  ${CP} -R include/* ${PREFIX}/include/elk; \
	  rm -rf bin include)
	@${INSTALL_MAN} ${WRKSRC}/doc/man/elk.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
