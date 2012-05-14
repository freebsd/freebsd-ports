# New ports collection makefile for:	pretty.go
# Date created:				4 Nov, 2010
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	prettygo
PORTVERSION=	20120306
CATEGORIES=	devel
MASTER_SITES=	LOCAL/jlaffaye

MAINTAINER=	magik@roorback.net
COMMENT=	Pretty-printing package for go values

USE_GO=		yes
GO_PKGNAME=	github.com/kr/pretty

SUBLIBDIR=	github.com/kr

do-install:
	${MKDIR} ${GO_LOCAL_LIBDIR}/${SUBLIBDIR}
	${INSTALL_DATA} ${GO_WRKDIR_PKG}/${SUBLIBDIR}/pretty.a ${GO_LOCAL_LIBDIR}/${SUBLIBDIR}
	${MKDIR} ${GO_LOCAL_SRCDIR}/${GO_PKGNAME}
.for f in diff.go formatter.go pretty.go
	${INSTALL_DATA} ${GO_WRKSRC}/${f} ${GO_LOCAL_SRCDIR}/${GO_PKGNAME}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
