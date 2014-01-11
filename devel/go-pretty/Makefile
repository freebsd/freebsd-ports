# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	go-pretty
PORTVERSION=	20130510
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	LOCAL/gblach/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Pretty-printing package for go values

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/github.com/kr/text.a:${PORTSDIR}/textproc/go-text
RUN_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/github.com/kr/text.a:${PORTSDIR}/textproc/go-text

GO_PKGNAME=	github.com/kr/pretty

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
