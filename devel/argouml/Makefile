# ex:ts=8
# Ports collection makefile for:	ArgoUML
# Date created:			June 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	argouml
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://argouml.tigris.org/files/documents/4/0/argouml-0.14/
DISTNAME=	ArgoUML-${PORTVERSION}

MAINTAINER=	philip.reynolds@rfc-networks.ie
COMMENT=	A UML design tool with cognitive support

NO_WRKSUBDIR=	yes
USE_JAVA=	1.3+
NO_BUILD=	yes

post-patch:
	@${SED} 's,%%DATADIR%%,${DATADIR},' ${FILESDIR}/argouml > \
		${WRKSRC}/argouml

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/argouml ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.jar ${DATADIR}

.include <bsd.port.mk>
