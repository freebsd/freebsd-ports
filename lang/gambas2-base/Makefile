# New ports collection makefile for:	gambas2-base
# Date created:		2009-01-16
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gambas2
PORTVERSION=	2.15.2
CATEGORIES?=	lang kde
MASTER_SITES=	SF/${PORTNAME:S/2//g}/${PORTNAME}/${PORTVERSION}
PKGNAMESUFFIX?=	-base

MAINTAINER=	acm@FreeBSD.org
COMMENT?=	A basic language with object extensions

BUILD_DEPENDS=	xdg-mime:${PORTSDIR}/devel/xdg-utils
LIB_DEPENDS=	ffi.5:${PORTSDIR}/devel/libffi

USE_AUTOTOOLS=		autoconf:262:env automake:19:env
USE_BZIP2=		yes
GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes
CPPFLAGS+=		-I${LOCALBASE}/include ${PTHREAD_LIBS}
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=		--disable-debug \
			--disable-optimization \
			--disable-preloading \
			--with-intl-includes=${LOCALBASE}/include \
			--with-intl-libraries=${LOCALBASE}/lib \
			--with-conv-includes=${LOCALBASE}/include \
			--with-conv-libraries=${LOCALBASE}/lib
CONFIGURE_WRKSRC?=	${WRKSRC}/main
BUILD_WRKSRC?=		${WRKSRC}/main
INSTALL_WRKSRC?=	${WRKSRC}/main

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - "${DISTNAME}/acinclude.m4" "${DISTNAME}/component.am" \
			"${DISTNAME}/config.sub" "${DISTNAME}/depcomp" "${DISTNAME}/install-sh" \
			"${DISTNAME}/ltmain.sh" "${DISTNAME}/COPYING" "${DISTNAME}/config.guess" \
			"${DISTNAME}/ChangeLog" "${DISTNAME}/missing" "${DISTNAME}/main"

.include <bsd.port.pre.mk>

.if ${PKGNAMESUFFIX} == "-base"
USE_KDELIBS_VER=	3
.include <${PORTSDIR}/Mk/bsd.kde.mk>

post-patch:
	@cd ${WRKSRC} && \
		${FIND} * -type f -name configure -print0 | ${XARGS} -0 ${REINPLACE_CMD} \
			-e 's|-pipe -Wall -Wno-unused-value -fsigned-char|$$CFLAGS|g' \
			-e 's|-pipe -Wall -fno-exceptions -Wno-unused-value -fsigned-char|$$CXXFLAGS|g' \
			-e 's|-O0||g'
	@cd ${WRKSRC} && \
		${FIND} -E * -type f -iregex ".*\.(c|h)" -print0 | ${XARGS} -0 ${REINPLACE_CMD} \
			-e 's|.so.4|.so|g' -e 's|.so.3|.so|g'
	@cd ${WRKSRC} && \
		${FIND} * -type f -name Makefile.in -print0 | ${XARGS} -0 ${REINPLACE_CMD} \
			-e 's|(GAMBAS_VERSION) -r|(GAMBAS_VERSION) -p -r|g'
.else
.include "${MASTERDIR}/Makefile.components"
.endif

.include <bsd.port.post.mk>
