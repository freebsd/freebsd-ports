# Ports collection makefile for:  pear-Console_Table
# Date created:			  31 August 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Console_Table
PORTVERSION=	1.0.1
CATEGORIES=	devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP class that makes it easy to build console style tables

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

MANIFEST=	Table.php

do-install:
	@${CP} -Rp ${WRKSRC}/* ${PEARDIR}/Console
.for FILE in ${MANIFEST}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Console/${FILE}
.endfor

.include <bsd.port.post.mk>
