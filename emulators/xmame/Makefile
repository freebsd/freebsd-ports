# New ports collection makefile for:    xmame
# Version required:     0.33b6.1
# Date created:         8 Feb 1998
# Whom:                 Donald Burr <dburr@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1998/07/09 14:40:58 dburr Exp $
#

DISTNAME=	xmame-0.33b6.1
CATEGORIES=	emulators
MASTER_SITES=	ftp://drake.dit.upm.es/xmame/ftpsite/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dburr@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_GMAKE=	YES
MAKEFILE=	makefile.unix

MAN6=		xmame.6

post-install:
.ifdef NOPORTDOCS
	@echo "==> Extra documentation WILL NOT be installed."
.else
	@echo "==> Installing extra documentation..."
	${MKDIR} ${PREFIX}/lib/mame
	for DOC in CHEAT.DOC Changes MailList.notes README.unix mamelist.txt readme.dos whatsnew.txt; do ${INSTALL} -c -o bin -g bin -m 444 ${WRKSRC}/doc/$${DOC} ${PREFIX}/lib/mame/$${DOC}; done
.endif
	(cd ${PREFIX}/lib/mame; sh ${FILESDIR}/dos2unx CHEAT.DOC Changes MailList.notes README.unix cheat.dat mamelist.txt readme.dos whatsnew.txt)
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
