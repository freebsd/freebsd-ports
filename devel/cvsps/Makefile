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

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
