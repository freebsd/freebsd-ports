# New ports collection makefile for:	tcl-getopt
# Version required:			1.0
# Date created:				Mar 18, 1999
# Whom:					mi
#
# $Id: Makefile,v 1.1.1.1 1999/05/03 03:22:59 steve Exp $
#

DISTNAME=	tclGetOpts
PKGNAME=	tclGetOpts-1.0
CATEGORIES=	devel tcl75 tcl76 tcl80 tcl81
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/sorted/devel/

MAINTAINER=	mi@aldan.algebra.com

NO_BUILD=	YES

MANN=		getopt.n typedopts.n

do-install:
	${MKDIR} ${PREFIX}/lib/foxGetOpt
	${INSTALL_SCRIPT} \
		${FILESDIR}/pkgIndex.tcl \
		${WRKSRC}/foxTypedOpts.tcl \
		${WRKSRC}/foxGetOpt.tcl ${PREFIX}/lib/foxGetOpt/
	${INSTALL_MAN} ${WRKSRC}/getopt.n ${WRKSRC}/typedopts.n \
		${PREFIX}/man/mann/

.include <bsd.port.mk>
