# Created by: mi
# $FreeBSD$

PORTNAME=	tclGetOpts
PORTVERSION=	1.0
CATEGORIES=	devel tcl
MASTER_SITES=	http://www.waxandwane.com/toolbox/tclGetOpts/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	${PORTVERSION}.tar.gz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Pure TCL code for command line options parsing

NO_BUILD=	YES

MANN=		getopt.n typedopts.n

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/lib/foxGetOpt
	${INSTALL_SCRIPT} \
		${FILESDIR}/pkgIndex.tcl \
		${WRKSRC}/foxTypedOpts.tcl \
		${WRKSRC}/foxGetOpt.tcl ${PREFIX}/lib/foxGetOpt/
	${INSTALL_MAN} ${WRKSRC}/getopt.n ${WRKSRC}/typedopts.n \
		${PREFIX}/man/mann/

.include <bsd.port.mk>
