# Created by: Anish Mistry <amistry@am-productions.biz>
# $FreeBSD$

PORTNAME=	lrmi
PORTVERSION=	0.10
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LRMI is a library for calling real mode BIOS routines

ONLY_FOR_ARCHS=	i386
USE_LDCONFIG=	yes
MAKEFILE=	Makefile.bsd

SHLIB_VERSION=	0
PLIST_SUB+=	"SHLIB_VERSION=${SHLIB_VERSION}"

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/liblrmi.so ${PREFIX}/lib/liblrmi.so.${SHLIB_VERSION}
	${LN} -fs ${PREFIX}/lib/liblrmi.so.${SHLIB_VERSION} ${PREFIX}/lib/liblrmi.so
	@${MKDIR} ${PREFIX}/include/lrmi
	${INSTALL_DATA} ${WRKSRC}/lrmi.h ${PREFIX}/include/lrmi
	${INSTALL_DATA} ${WRKSRC}/vbe.h ${PREFIX}/include/lrmi

.include <bsd.port.post.mk>
