# New ports collection makefile for:	noweb
# Version required:	noweb-2.8a
# Date created:		29 July 1995
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $Id: Makefile,v 1.10 1997/09/15 07:22:06 tg Exp $
#

DISTNAME=	noweb-2.8a
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.virginia.edu/pub/nr/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tg@freebsd.org

BUILD_DEPENDS=	icont:${PORTSDIR}/lang/icon
RUN_DEPENDS=	iconx:${PORTSDIR}/lang/icon

WRKSRC=		${WRKDIR}/src
MAN1=		cpif.1 nodefs.1 noroots.1 noweb.1 noindex.1 \
		nuweb2noweb.1 notangle.1 sl2h.1 htmltoc.1
MAN7=		nowebstyle.7 nowebfilters.7

post-build:
	@(cd ${WRKSRC} && ${WRKSRC}/awkname awk)

.if !defined(NOMANCOMPRESS)
post-install:
	@rm ${PREFIX}/man/man1/noweave.1*
	@rm ${PREFIX}/man/man1/nountangle.1*
	ln -sf ${PREFIX}/man/man1/notangle.1.gz ${PREFIX}/man/man1/noweave.1.gz
	ln -sf ${PREFIX}/man/man1/notangle.1.gz ${PREFIX}/man/man1/nountangle.1.gz
.endif

.include <bsd.port.mk>
