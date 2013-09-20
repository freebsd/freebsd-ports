# Created by: ijliao
# $FreeBSD$

PORTNAME=	cvsps
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cobite.com/cvsps/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create patchset information from CVS

CONFLICTS=	cvsps-devel-[0-9]*

MAN1=		cvsps.1
PLIST_FILES=	bin/cvsps

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsps ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cvsps.1 ${MANPREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
