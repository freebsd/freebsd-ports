# New ports collection makefile for:	noweb
# Version required:	noweb-2.7d
# Date created:		29 July 1995
# Whom:			thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.7 1996/11/18 11:23:26 asami Exp $
#

DISTNAME=	noweb-2.7d
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.purdue.edu/pub/nr/
EXTRACT_SUFX=	.tgz

MAINTAINER=	thomas@ghpc8.ihf.rwth-aachen.de

BUILD_DEPENDS=	icont:${PORTSDIR}/lang/icon
RUN_DEPENDS=	iconx:${PORTSDIR}/lang/icon

WRKSRC=		${WRKDIR}/src
MAN1=		htmltoc.1 nodefs.1 noindex.1 noroots.1 notangle.1 \
		noweb.1 cpif.1 sl2h.1 nowebstyle.1 nuweb2noweb.1 \
		nowebfilters.1

.if !defined(NOMANCOMPRESS)
post-install:
	@rm ${PREFIX}/man/man1/noweave.1*
	@rm ${PREFIX}/man/man1/nountangle.1*
	ln -sf ${PREFIX}/man/man1/notangle.1.gz ${PREFIX}/man/man1/noweave.1.gz
	ln -sf ${PREFIX}/man/man1/notangle.1.gz ${PREFIX}/man/man1/nountangle.1.gz
.endif

.include <bsd.port.mk>

