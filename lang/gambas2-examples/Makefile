# New ports collection makefile for:	gambas2-examples
# Date created:		2009-01-16
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gambas2
PORTVERSION=	2.15.0
CATEGORIES=	lang
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME:S/2//g}
PKGNAMESUFFIX=	-examples
DISTNAME=	${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME:S/2//g}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Example projects for gambas language

USE_BZIP2=	yes

NO_BUILD=	yes

FETCH_ARGS=		 -pRr
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - "${DISTNAME}/examples"

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}

.include <bsd.port.mk>
