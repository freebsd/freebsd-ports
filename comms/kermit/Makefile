# New ports collection makefile for:	kermit
# Version required:     6.0.192
# Date created:		Oct 27, 1994
# Whom:			pst
#
# $FreeBSD$
#

DISTNAME=	cku196
PKGNAME=        kermit-7.0.196-beta
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/test/tar/

MAINTAINER=	joerg@FreeBSD.org

NO_WRKSUBDIR=	yes
MAN1=		kermit.1
MANCOMPRESSED=	yes

post-install:
	@${MKDIR} ${PREFIX}/share/examples/kermit
	${INSTALL_DATA} ${FILESDIR}/dot.kermrc ${PREFIX}/share/examples/kermit
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
