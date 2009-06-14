# New ports collection makefile for:	bouml-doc
# Date created:		23 December 2007
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	bouml-doc
PORTVERSION=	4.12.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}	\
		http://bouml.free.fr/
MASTER_SITE_SUBDIR=	bouml
DISTNAME=	doc${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Reference manual of BOUML

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/doc
DOCSDIR=	${PREFIX}/share/doc/bouml

do-install:
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DOCSDIR})

.include <bsd.port.mk>
