# New ports collection makefile for:	TclCheck
# Version required:		1.1.11
# Date created:			28 June 1997
# Whom:				Sander Vesik <sander@haldjas.folklore.ee>
#
# $Id: Makefile,v 1.1.1.1 1997/07/21 16:09:00 max Exp $
#

DISTNAME=	tclCheck-1.1.11
PKGNAME=	tclcheck-1.1.11
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.neosoft.com/languages/tcl/sorted/devel/

MAINTAINER=	sander@haldjas.folklore.ee

MAN1=		tclCheck.1
MANCOMPRESSED=	yes

pre-build:
	@${CP} -f ${FILESDIR}/Makefile ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tclCheck
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/tclCheck
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tclCheck
.endif

.include <bsd.port.mk>
