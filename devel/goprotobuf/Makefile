# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	goprotobuf
PORTVERSION=	20120409
CATEGORIES=	devel
MASTER_SITES=	LOCAL/jlaffaye

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Go support for Google's protocol buffers

LICENSE=	BSD

RUN_DEPENDS=	protoc:${PORTSDIR}/devel/protobuf

GO_PKGNAME=	code.google.com/p/goprotobuf
GO_TARGET=	${GO_PKGNAME}/proto ${GO_PKGNAME}/protoc-gen-go

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/protoc-gen-go ${LOCALBASE}/bin
	${MKDIR} ${GO_LOCAL_LIBDIR}/${GO_PKGNAME}
	(cd ${GO_WRKDIR_PKG}/${GO_PKGNAME}/ && ${COPYTREE_SHARE} \* ${GO_LOCAL_LIBDIR}/${GO_PKGNAME})
	${MKDIR} ${GO_LOCAL_SRCDIR}/${GO_PKGNAME}/proto
	(cd ${GO_WRKSRC}/proto && ${COPYTREE_SHARE} \*	\
		${GO_LOCAL_SRCDIR}/${GO_PKGNAME}/proto)

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
