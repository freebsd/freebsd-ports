# ex:ts=8
# Ports collection makefile for:	PyChart
# Date created:			Aug 4, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	chart
PORTVERSION=	1.37
CATEGORIES=	graphics python
MASTER_SITES=	http://download.gna.org/pychart/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyChart-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create high quality Encapsulated Postscript, PDF, or PNG charts

USE_GHOSTSCRIPT_RUN=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
