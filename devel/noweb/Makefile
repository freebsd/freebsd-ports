# New ports collection makefile for:	noweb
# Version required:	noweb-2.7d
# Date created:		29 July 1995
# Whom:			thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.4 1995/11/26 11:29:17 asami Exp $
#

DISTNAME=	noweb-2.7d
CATEGORIES+=	devel
MASTER_SITES=	ftp://ftp.cs.purdue.edu/pub/nr/
EXTRACT_SUFX=	.tgz

MAINTAINER=	thomas@ghpc8.ihf.rwth-aachen.de

BUILD_DEPENDS=	icont:${PORTSDIR}/lang/icon
RUN_DEPENDS=	iconx:${PORTSDIR}/lang/icon

WRKSRC=		${WRKDIR}/src

.if !defined(NOMANCOMPRESS)
post-install:
	for i in htmltoc nodefs noindex noroots notangle noweb cpif sl2h nowebstyle nuweb2noweb nowebfilters; \
	do \
		gzip -9nf ${PREFIX}/man/man1/$$i.1; \
	done
	@rm ${PREFIX}/man/man1/noweave.1*
	@rm ${PREFIX}/man/man1/nountangle.1*
	ln ${PREFIX}/man/man1/notangle.1.gz ${PREFIX}/man/man1/noweave.1.gz
	ln ${PREFIX}/man/man1/notangle.1.gz ${PREFIX}/man/man1/nountangle.1.gz
.endif

.include <bsd.port.mk>

