# Ports collection makefile for:  pear-Console_Getopt
# Date created:			  23 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Console_Getopt
PORTVERSION=	1.2
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR command-line option parser

BUILD_DEPENDS=	pear:${PORTSDIR}/lang/php4
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Console/Getopt.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
