# New ports collection makefile for:	opentop
# Date created:				17 November 2003
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	opentop
PORTVERSION=	1.3.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	open-top
DISTNAME=	${PORTNAME}-${PORTVERSION:C|\.|-|g}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DOCDIST}${EXTRACT_SUFX}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	A cross-platform C++ framework library

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

DOCDIST=	${PORTNAME}-api-${PORTVERSION:C|\.[0-9]$||:C|\.|-|g}

OPTIONS=	DEBUG "Build library with debug symbols" off \
		SINGLE_THRD "Build single-threaded library" off \
		WCHAR "Build wchar_t support library instead of char" off \
		STATIC "Build static library instead of dynamic" off

.include <bsd.port.pre.mk>

# Defaults: always build release, multi-threaded, char supported, shared
TYPE=		release
THREAD=		multi
CHAR=		char
LIBS=		shared

.if defined(WITH_DEBUG)
TYPE+=		debug
.endif
.if defined(WITH_SINGLE_THRD)
THREAD+=	single
.endif
.if defined(WITH_WCHAR)
CHAR+=		wchar
.endif
.if defined(WITH_STATIC)
LIBS+=		static
.endif

PLIST_FILES!=for r in ${TYPE}; do \
		for t in ${THREAD}; do \
			for c in ${CHAR}; do \
				for l in ${LIBS}; do \
					type=""; thread=""; \
			 		char=""; ext="so"; \
					if [ "$$r" = "debug" ]; then \
						type="d"; \
					fi; \
					if [ "$$t" = "multi" ]; then \
						thread="mt"; \
					fi; \
					if [ "$$c" = "wchar" ]; then \
						char="w"; \
					fi; \
					if [ "$$l" = "static" ]; then \
						ext="a"; \
					fi; \
	${ECHO_CMD} "lib/libopentop-gcc$${char}$${thread}$${type}.$${ext}"; \
	${ECHO_CMD} "lib/libotxml-gcc$${char}$${thread}$${type}.$${ext}"; \
				done; \
			done;\
		done; \
	done

.for r in ${TYPE}
.for t in ${THREAD}
.for c in ${CHAR}
.for l in ${LIBS}
ALL_TARGET+=	$r_$t_$c_$l
.endfor
.endfor
.endfor
.endfor

post-patch:
	@${REINPLACE_CMD} "s/-O3/${CFLAGS}/" \
		${WRKSRC}/buildtools/cxx_compiler_options \
		${WRKSRC}/buildtools/gcc_compiler_options

do-install:
	@${MKDIR} ${PREFIX}/include/${PORTNAME}; \
	cd ${WRKSRC}; ${FIND} ot \( -name "*.h" -o -name "*.inl" \) -print | \
			${TAR} cTf - - | \
			${TAR} xUCf ${PREFIX}/include/${PORTNAME} - ; \
	${FIND} lib \( -name "*.so" -o -name "*.a" \) -exec \
		${INSTALL_PROGRAM} \{\} ${PREFIX}/lib \;
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKDIR}/${DOCDIST}/html; ${TAR} cf - . | ${TAR} xUCf ${DOCSDIR} -
.endif

.include <bsd.port.post.mk>
