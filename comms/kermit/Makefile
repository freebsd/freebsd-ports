# New ports collection makefile for:	kermit
# Version required:	5A(190)
# Date created:		Oct 27, 1994
# Whom:			pst
# Changed:		ats, Nov 16, 1994
#
# $Id: Makefile,v 1.10 1996/12/07 11:12:21 max Exp $
#

DISTNAME=	cku190
PKGNAME=	kermit-5a.190
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/ \
		ftp://ftp.th-darmstadt.de/pub/networking/kermit/ \
		ftp://ftp.std.com/customers2/src/telcom/

MAINTAINER=	pst@FreeBSD.org

RESTRICTED=	"'No redistribution' copyright"
NO_WRKSUBDIR=	yes

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
