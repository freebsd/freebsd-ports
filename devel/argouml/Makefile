# ex:ts=8
# Ports collection makefile for:	ArgoUML
# Date created:			June 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	argouml
PORTVERSION=	0.12
CATEGORIES=	devel
MASTER_SITES=	http://argouml.tigris.org/files/documents/4/1087/
DISTNAME=	ArgoUML-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A UML design tool with cognitive support

NO_WRKSUBDIR=	yes
USE_JAVA=	1.2+
NO_BUILD=	yes

post-patch:
	@${SED} 's,%%DATADIR%%,${DATADIR},' ${FILESDIR}/argouml > \
		${WRKSRC}/argouml

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/argouml ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.jar ${DATADIR}

.include <bsd.port.mk>
