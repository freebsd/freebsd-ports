# New ports collection makefile for:	kermit
# Version required:     6.0.192
# Date created:		Oct 27, 1994
# Whom:			pst
#
# $Id: Makefile,v 1.15 1997/01/18 19:32:38 max Exp $
#

DISTNAME=	cku192src
PKGNAME=        kermit-6.0.192
CATEGORIES=	comms

MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/ \
		ftp://ftp.th-darmstadt.de/pub/networking/kermit/ \
		ftp://ftp.std.com/customers2/src/telcom/

MAINTAINER=	ports@FreeBSD.org

RESTRICTED=	"'No redistribution' copyright"
NO_WRKSUBDIR=	yes
MAN1=		kermit.1
MANCOMPRESSED=	yes

post-install:
	@${MKDIR} ${PREFIX}/share/examples/kermit
	${INSTALL_DATA} ${FILESDIR}/dot.kermrc ${PREFIX}/share/examples/kermit
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
