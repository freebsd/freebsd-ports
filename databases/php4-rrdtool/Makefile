# New ports collection makefile for:	php4-rrdtool
# Date created:				26 Aug 2004
# Whom:					mat
#
# $FreeBSD$
#

PORTNAME=	rrdtool
PORTVERSION=	1.05
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_LOCAL} http://www.joeym.net/
MASTER_SITE_SUBDIR=	mat
PKGNAMEPREFIX=	php4-
DISTNAME=	${UNIQUENAME}-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A php/rrdtool glue

LIB_DEPENDS=	rrd:${PORTSDIR}/databases/rrdtool

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${UNIQUENAME}-${PORTVERSION}

USE_PHP=	yes
USE_PHPEXT=	yes

.if !defined(NOPORTEXAMPLES)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
