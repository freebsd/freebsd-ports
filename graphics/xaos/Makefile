# New ports collection makefile for:	XaoS
# Version required:			2.2
# Date created:				24 February 1996
# Whom:					Joseph Koshy <koshy@india.hp.com>
#
# $Id: Makefile,v 1.3 1997/07/01 17:41:01 jfitz Exp $
#

DISTNAME=	XaoS-2.2
PKGNAME=	xaos-2.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB} \
		ftp://ftp.ta.jcu.cz/pub/linux/hubicka/XaoS/2.2/ \
		http://www.paru.cas.cz/~hubicka/XaoS/dist/
MASTER_SITE_SUBDIR=	graphics

MAINTAINER=	jkoshy@freebsd.org

# This port will benefit from all-stops-out optimization of the code

GNU_CONFIGURE=	yes
CFLAGS+=	-DHAVE_SYS_PARAM_H \
		-O6 -fstrength-reduce -ffast-math -fomit-frame-pointer\
		-fforce-mem -fforce-addr -funroll-loops

MAN6=		xaos.6

# We need to supply our own install target as the distribution doesn't
# supply one by default

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xaos ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xaos.6 ${PREFIX}/man/man6

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/XaoS
	${INSTALL_DATA} ${WRKSRC}/doc/tutorial.txt ${PREFIX}/share/doc/XaoS
	${INSTALL_DATA} ${WRKSRC}/doc/algorithm.txt ${PREFIX}/share/doc/XaoS
.endif

.include <bsd.port.mk>
