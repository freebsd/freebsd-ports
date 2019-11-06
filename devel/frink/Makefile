# Created by: Mikhail Teterin
# $FreeBSD$

PORTNAME=	frink
PORTVERSION=	2.2.2p4
CATEGORIES=	devel
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Tcl formatter and static tester

BROKEN=		unfetchable

WRKSRC=		${WRKDIR}/${PORTNAME}-2.2.2
USES=		uidfix
MAKEFILE=	${FILESDIR}/Makefile.bsd

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
