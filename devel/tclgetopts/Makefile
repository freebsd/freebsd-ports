# New ports collection makefile for:	tcl-getopt
# Date created:				Mar 18, 1999
# Whom:					mi
#
# $FreeBSD$
#

PORTNAME=	tclGetOpts
PORTVERSION=	1.0
CATEGORIES=	devel tcl76 tcl80 tcl82
MASTER_SITES=	ftp://ftp.neosoft.com/languages/tcl/alcatel/code/ \
		http://www.neosoft.com/tcl/ftparchive/alcatel/code/
DISTNAME=	${PORTNAME}

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
