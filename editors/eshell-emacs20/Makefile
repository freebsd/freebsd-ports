# New ports collection makefile for:   eshell for emacs20
# Date Created:			2 Dec 2001
# Whom:				Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eshell
PORTVERSION=	2.4.2
CATEGORIES=	editors elisp
MASTER_SITES=	http://www.newartisans.com/johnw/Emacs/packages/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}

MAINTAINER=	yoichi@FreeBSD.org
COMMENT=	Command shell implemented in emacs lisp

EMACS_PORT_NAME=	emacs20

PCOMPLETE_VERSION=	1.1.7

MAKE_ARGS+=	lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} \
		CP="${INSTALL_DATA}"

ALL_TARGET=	default
INFO=		eshell

post-extract:
	@(cd ${WRKSRC}; ${TAR} zxf ${PORTNAME}.tar.gz; \
	${TAR} zxf pcomplete-${PCOMPLETE_VERSION}.tar.gz)

do-build:
	@(cd ${WRKSRC}/${PORTNAME}-${PORTVERSION}; \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
	@(cd ${WRKSRC}/pcomplete-${PCOMPLETE_VERSION}; \
	${RM} auto-autoloads.el; \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@(cd ${WRKSRC}/${PORTNAME}-${PORTVERSION}; \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
	@(cd ${WRKSRC}/pcomplete-${PCOMPLETE_VERSION}; \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.mk>
