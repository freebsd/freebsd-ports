# New ports collection makefile for:	kermit
# Version required:	5A(190)
# Date created:		Oct 27, 1994
# Whom:			pst
# Changed:		ats, Nov 16, 1994
#

DISTNAME=	cku190
PKGNAME=	kermit-5a.190
CATEGORIES+=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/ \
		ftp://ftp.th-darmstadt.de/pub/networking/kermit/ \
		ftp://ftp.std.com/customers2/src/telcom/

NO_WRKSUBDIR=	yes
RESTRICTED=	"'No redistibution' copyright."

post-install:
	@cat ${PKGDIR}/DESCR

.include <bsd.port.mk>
