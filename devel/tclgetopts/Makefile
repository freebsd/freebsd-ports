# New ports collection makefile for:	tcl-getopt
# Version required:			1.0
# Date created:				Mar 18, 1999
# Whom:					mi
#
# $FreeBSD$
#

DISTNAME=	tclGetOpts
PKGNAME=	tclGetOpts-1.0
CATEGORIES=	devel tcl76 tcl80 tcl82
MASTER_SITES= ftp://ftp.neosoft.com/languages/tcl/sorted/packages-7.6/devel/ \
	      http://www.neosoft.com/tcl/ftparchive/sorted/packages-7.6/devel/

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
