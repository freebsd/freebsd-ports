# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	go-pretty
PORTVERSION=	20130510
CATEGORIES=	devel
MASTER_SITES=	LOCAL/gblach/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Pretty-printing package for go values

BUILD_DEPENDS=	${LOCALBASE}/go/pkg/${OPSYS:L}_${GOARCH}/github.com/kr/text.a:${PORTSDIR}/textproc/go-text
RUN_DEPENDS=	${LOCALBASE}/go/pkg/${OPSYS:L}_${GOARCH}/github.com/kr/text.a:${PORTSDIR}/textproc/go-text

SUBLIBDIR=	github.com/kr
GO_PKGNAME=	${SUBLIBDIR}/pretty

do-install:
	${MKDIR} ${GO_LOCAL_LIBDIR}/${SUBLIBDIR}
	${INSTALL_DATA} ${GO_WRKDIR_PKG}/${SUBLIBDIR}/pretty.a ${GO_LOCAL_LIBDIR}/${SUBLIBDIR}
	${MKDIR} ${GO_LOCAL_SRCDIR}/${GO_PKGNAME}
.for f in diff.go formatter.go pretty.go zero.go
	${INSTALL_DATA} ${GO_WRKSRC}/${f} ${GO_LOCAL_SRCDIR}/${GO_PKGNAME}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
