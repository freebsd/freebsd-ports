# New ports collection makefile for:  gcin
# Date created:                   Feb 18 2004
# Whom:                           Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	gcin
PORTVERSION=	0.2.0
CATEGORIES=	chinese
MASTER_SITES=	http://www.csie.nctu.edu.tw/~cp76/gcin/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A triditional chinese input utility in X

USE_BZIP2=	YES
HAS_CONFIGURE=	YES
USE_GNOME=	gtk20
USE_GMAKE=	YES

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500041
USE_GCC=	3.3
.endif

.include <bsd.port.post.mk>
