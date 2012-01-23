# New ports collection makefile for:	goprotobuf
# Date created:		2012-01-22
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	goprotobuf
PORTVERSION=	20120122
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://m.ahze.net/packages/ \
		LOCAL/ahze

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Go support for Google's protocol buffers

LICENSE=	BSD

RUN_DEPENDS=	protoc:${PORTSDIR}/devel/protobuf

USE_GO=		yes
NO_BUILD=	yes
MAKE_ENV=	GOBIN=${PREFIX}/bin

post-install:
	${INSTALL} -d ${GOROOT}/src/pkg/goprotobuf.googlecode.com/hg/
	${INSTALL} -m 644 ${WRKSRC}/Make.protobuf ${GOROOT}/src/pkg/goprotobuf.googlecode.com/hg/

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
