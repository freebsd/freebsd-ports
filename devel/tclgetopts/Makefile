# New ports collection makefile for:	tcl-getopt
# Date created:				Mar 18, 1999
# Whom:					mi
#
# $FreeBSD$
#

PORTNAME=	tclGetOpts
PORTVERSION=	1.0
CATEGORIES=	devel tcl80 tcl82 tcl83 tcl84
MASTER_SITES=	http://www.waxandwane.com/toolbox/tclGetOpts/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	${PORTVERSION}.tar.gz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Pure TCL code for command line options parsing

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
