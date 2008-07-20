# New ports collection makefile for:	TclCheck
# Date created:			28 June 1997
# Whom:				Sander Vesik <sander@haldjas.folklore.ee>
#
# $FreeBSD$
#

PORTNAME=	tclcheck
PORTVERSION=	1.1.13
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/
DISTNAME=	tclCheck-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to check the nesting of parenthesis in tcl scripts

MAN1=		tclCheck.1
MANCOMPRESSED=	yes

pre-build:
	@${CP} -f ${FILESDIR}/Makefile ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
