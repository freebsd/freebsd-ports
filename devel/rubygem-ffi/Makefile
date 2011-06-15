# New ports collection makefile for:   rubygem-ffi
# Date created:    28 April 2010
# Whom:	Christoph Kick
#
# $FreeBSD$
#

PORTNAME=	ffi
PORTVERSION=	1.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Extension for dynamic libraries & binding functions

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.8
PLIST_FILES=	${GEM_LIB_DIR}/ext/ffi_c/libffi/include/ffitarget.h \
				${GEM_LIB_DIR}/ext/ffi_c/libffi/.libs/libffi.so \
				${GEM_LIB_DIR}/ext/ffi_c/libffi/.libs/libffi.la \
				${GEM_LIB_DIR}/ext/ffi_c/libffi/.libs/libffi_convenience.la
.endif

.include <bsd.port.post.mk>
