# Ports collection makefile for:  pear-Date
# Date created:			  28 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Date
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Date and Time Zone Classes

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

MANIFEST=	Date Date.php

do-install:
	@${CP} -Rp ${WRKSRC}/* ${PEARDIR}
.for FILE in ${MANIFEST}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/${FILE}
.endfor

.include <bsd.port.post.mk>
