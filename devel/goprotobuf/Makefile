# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	goprotobuf
PORTVERSION=	20131010
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Go support for Google's protocol buffers

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	protoc:${PORTSDIR}/devel/protobuf

GO_PKGNAME=	code.google.com/p/goprotobuf
GO_TARGET=	${GO_PKGNAME}/proto ${GO_PKGNAME}/protoc-gen-go

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
