# Created by: Chris Larsen <darth@vader.dk>
# $FreeBSD$

PORTNAME=	par2cmdline
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	SF/parchive/${PORTNAME}/${PORTVERSION}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Tools for using Parity v2 Archive files

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

PORTDOCS=	README
CONFLICTS=	par2cmdline-tbb-[0-9]*

PLIST_FILES=	bin/par2 bin/par2create bin/par2repair bin/par2verify

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
