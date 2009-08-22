# New ports collection makefile for:	par2cmdline
# Whom:					Chris Larsen <darth@vader.dk>
# Date created:				24 July 2003
#
# $FreeBSD$
#

PORTNAME=	par2cmdline
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	SF/parchive/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Tools for using Parity v2 Archive files

GNU_CONFIGURE=	yes

PORTDOCS=	README
CONFLICTS=	par2cmdline-tbb-[0-9]*
PLIST_FILES=	bin/par2 bin/par2create bin/par2repair bin/par2verify

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
