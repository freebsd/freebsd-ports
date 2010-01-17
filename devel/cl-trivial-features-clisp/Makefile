# New ports collection makefile for:	cl-trivial-features-clisp
# Date created:				16 January 2010
# Whom:					Jimmy Olgeni <olgeni@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	trivial-features
PORTVERSION=	2010.01.16
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Ensures consistent *FEATURES* in Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/trivial-features.asd:${PORTSDIR}/devel/cl-trivial-features
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/trivial-features.asd:${PORTSDIR}/devel/cl-trivial-features

USE_ASDF_FASL=	yes
FASL_TARGET=	clisp
FASL_BUILD=	yes

do-install:
	@${MKDIR} ${ASDF_PATHNAME}/src/${FASL_DIR_REL}
	@${INSTALL_DATA} ${WRKSRC}/*.fasl ${ASDF_PATHNAME}/src/${FASL_DIR_REL}

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
