# New ports collection makefile for:	libjit
# Date created:		2004-04-27
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	libjit
PORTVERSION=	0.0.2
CATEGORIES=	lang
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	ahze@ahze.net
COMMENT=	Libjit implements Just-In-Time compilation functionality

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INFO=		libjit
MAN3=		libjit.3
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not compile on amd64"
.endif

.include <bsd.port.post.mk>
