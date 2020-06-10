# Created by: Mikhail Teterin
# $FreeBSD$

PORTNAME=	frink
PORTVERSION=	2.2.2p4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://BSDforge.COM/projects/source/devel/frink/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Tcl formatter and static tester

LICENSE=	COPYRIGHT
LICENSE_NAME=	The University of Newcastle upon Tyne
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	auto-accept

WRKSRC=		${WRKDIR}/${PORTNAME}-2.2.2
USES=		uidfix
MAKEFILE=	${FILESDIR}/Makefile.bsd

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
