# New ports collection makefile for:   nickle
# Date created:        16 April 2001
# Whom:                Christopher Elkins <chrise@scardini.com>
#
# $FreeBSD$
#

PORTNAME=	nickle
PORTVERSION=	2.00
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.nickle.org/release/

MAINTAINER=	chrise@scardini.com
COMMENT=	A desk calculator language

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=	nickle.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile"
.endif

.include <bsd.port.post.mk>
