# New ports collection makefile for:	noweb
# Version required:	noweb-2.7a
# Date created:		29 July 1995
# Whom:			thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id$
#

DISTNAME=	noweb-2.7a
CATEGORIES+=	development documentation
KEYWORDS+=	development documentation "literate programming"
MASTER_SITES=	ftp://bellcore.com/pub/norman/
EXTRACT_SUFX=	.tgz

MAINTAINER=	thomas@ghpc8.ihf.rwth-aachen.de

EXEC_DEPENDS=	icont:${PORTSDIR}/lang/icon

WRKSRC=		${WRKDIR}/src

.if !defined(NOMANCOMPRESS)
post-install:
	for i in nodefs noindex noroots notangle noweb cpif sl2h nowebstyle nuweb2noweb nowebfilters; \
	do \
		gzip -9nf ${PREFIX}/man/man1/$$i.1; \
	done
	@rm ${PREFIX}/man/man1/noweave.1*
	@rm ${PREFIX}/man/man1/nountangle.1*
	ln ${PREFIX}/man/man1/notangle.1.gz ${PREFIX}/man/man1/noweave.1.gz
	ln ${PREFIX}/man/man1/notangle.1.gz ${PREFIX}/man/man1/nountangle.1.gz
.endif

.include <bsd.port.mk>

