# ex:ts=8
# Ports collection makefile for:	PyChart
# Date created:			Aug 4, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	chart
PORTVERSION=	1.28.1
CATEGORIES=	graphics python
MASTER_SITES=	http://www.hpl.hp.com/personal/Yasushi_Saito/pychart/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyChart-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create high quality Encapsulated Postscript, PDF, or PNG charts

.if defined(WITH_GHOSTSCRIPT_AFPL) && ${WITH_GHOSTSCRIPT_AFPL} == yes
GSPORT?=	print/ghostscript-afpl
.else
GSPORT?=	print/ghostscript-gnu
.endif

RUN_DEPENDS=	gs:${PORTSDIR}/${GSPORT}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
