# New ports collection makefile for:   rubygem-ffi
# Date created:    28 April 2010
# Whom:	Christoph Kick
#
# $FreeBSD$
#

PORTNAME=	ffi
PORTVERSION=	0.5.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	kick.christoph@googlemail.com
COMMENT=	Extension for dynamic libraries & binding functions

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	${GEM_LIB_DIR}/ext/ffi_c/libffi/include/ffitarget.h \
				${GEM_LIB_DIR}/ext/ffi_c/libffi/.libs/libffi.so \
				${GEM_LIB_DIR}/ext/ffi_c/libffi/.libs/libffi.la \
				${GEM_LIB_DIR}/ext/ffi_c/libffi/.libs/libffi_convenience.la

.include <bsd.port.mk>
