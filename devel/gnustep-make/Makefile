# New ports collection makefile for:    gnustep-make
# Date created:         17 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-make
PORTVERSION=	1.11.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep makefile package

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL} -c" INSTALL_DATA="${INSTALL} -c" \
		CFLAGS="${CFLAGS}"
CONFIGURE_TARGET=
USE_GMAKE=	yes
USE_GNUSTEP=	yes
MAKEFILE=
MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ARGS+=	--with-thread-lib="${PTHREAD_LIBS}"

.if defined(GNUSTEP_WITH_BASE_GCC)
GNUSTEP_WITHOUT_LIBOBJC=	yes
.endif

.include <bsd.port.pre.mk>

.if !defined(GNUSTEP_WITH_BASE_GCC)
pre-configure:
	@if test ! -f "${TARGLIB}/libobjc.so"; then \
		${ECHO_MSG} "libobjc.so not found, please update your gcc"; \
		${FALSE}; \
	fi; \
	if test `${LDCONFIG} -r | ${GREP} "${TARGLIB}/libobjc.so" | wc -l` -eq 0; then \
		${ECHO_MSG} "trying to fix ldconfig.hints"; \
		${LDCONFIG} -f "${WRKDIR}/ldconfig.hints" -m "${TARGLIB}";\
		if test `${LDCONFIG} -f "${WRKDIR}/ldconfig.hints" -r | ${GREP} "${TARGLIB}/libobjc.so" | wc -l` -eq 0; then \
			${ECHO_MSG} "libobjc.so not in path"; \
			${FALSE}; \
		fi; \
	fi;
.endif

post-install:
	${LN} -s Library/Makefiles ${PREFIX}/System/

.if defined(PARALLEL_PACKAGE_BUILD)
NO_PACKAGE=	yes
.endif

.include <bsd.port.post.mk>
