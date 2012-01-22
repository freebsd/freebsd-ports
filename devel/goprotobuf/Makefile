# New ports collection makefile for:	goprotobuf
# Date created:		2012-01-22
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	goprotobuf
PORTVERSION=	20120122
CATEGORIES=	devel
MASTER_SITES=	http://m.ahze.net/packages/ \
		LOCAL/ahze

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Go support for Google's protocol buffers

USE_GO=		yes
NO_BUILD=	yes
MAKE_ENV=	GOBIN=${PREFIX}/bin

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
