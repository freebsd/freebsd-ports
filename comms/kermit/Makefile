# New ports collection makefile for:	kermit
# Version required:	6(192)
# Date created:		Oct 27, 1994
# Whom:			pst
#
# $Id: Makefile,v 1.11 1996/12/08 01:44:33 max Exp $
#

DISTNAME=	cku192src
PKGNAME=	kermit-6.192
CATEGORIES+=	comms

MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/ \
		ftp://ftp.th-darmstadt.de/pub/networking/kermit/ \
		ftp://ftp.std.com/customers2/src/telcom/

MAINTAINER=	pst@FreeBSD.org

RESTRICTED=	"'No redistribution' copyright"
NO_WRKSUBDIR=	yes

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
