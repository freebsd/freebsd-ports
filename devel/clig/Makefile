# New ports collection makefile for:   clig
# Date created:        27 July 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	clig
PORTVERSION=	1.9.11.1
PORTREVISION=	1
CATEGORIES=	devel tcl
MASTER_SITES=	http://wsd.iitb.fhg.de/~geg/clighome/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Auto-generate an (argc, argv) processor, usage message, and manpage

NO_BUILD=	yes
USE_TCL_BUILD=	yes
USE_TCL=	yes
MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		clig.1
MANN=		clig_Commandline.n clig_Description.n clig_Double.n clig_Flag.n \
		clig_Float.n clig_Int.n clig_Long.n clig_Name.n clig_Rest.n \
		clig_String.n clig_Usage.n clig_Version.n clig_parseCmdline.n

post-patch:
	@${RM} ${WRKSRC}/example/.cvsignore
	@${FIND} -d ${WRKSRC} -type d -and -name CVS -exec ${RM} -r {} \;
	@${REINPLACE_CMD} -e 's|prefix =/usr|prefix=${PREFIX}|; \
		s|/usr/bin/tclsh|${TCLSH}|; \
		s|/doc/|/share/doc/|; \
		s|-$$(VERSION)||;' \
			${WRKSRC}/makefile
	@${REINPLACE_CMD} -e "s|tclsh|${TCLSH}|" \
		${WRKSRC}/man/fixman

.include <bsd.port.mk>
