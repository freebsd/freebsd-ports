# New ports collection makefile for:	TclCheck
# Date created:			28 June 1997
# Whom:				Sander Vesik <sander@haldjas.folklore.ee>
#
# $FreeBSD$
#

PORTNAME=	tclcheck
PORTVERSION=	1.1.13
CATEGORIES=	devel
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/
DISTNAME=	tclCheck-${PORTVERSION}

MAINTAINER=	sander@haldjas.folklore.ee
COMMENT=	A program to check the nesting of parenthesis in tcl scripts

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
