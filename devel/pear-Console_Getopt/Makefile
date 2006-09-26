# Ports collection makefile for:  pear-Console_Getopt
# Date created:			  2006/08/02
# Whom:				  chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Console_Getopt
PORTVERSION=	1.2
CATEGORIES=	devel pear

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	PHP class that provides Command-line option parser

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Console
FILES=		Console/Getopt.php

post-patch:
	@${CP} ${FILESDIR}/package.xml ${WRKDIR}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
