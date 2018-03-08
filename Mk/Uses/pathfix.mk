# $FreeBSD$
#
# Lookup common paths in Makefile.in, configure and similar files, and replace
# their values to respect FreeBSD hier(7) for file installation.
#
# Feature:	pathfix
# Usage:	USES=pathfix
# Valid ARGS:	does not require args
#
# MAINTAINER: portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_PATHFIX_MK)
_INCLUDE_USES_PATHFIX_MK=	yes

.if !empty(pathfix_ARGS)
IGNORE=	USES=pathfix does not require args
.endif

PATHFIX_CMAKELISTSTXT?=	CMakeLists.txt
.if ${USES:Mautoreconf*}
PATHFIX_MAKEFILEIN?=	Makefile.am Makefile.in
.else
PATHFIX_MAKEFILEIN?=	Makefile.in
.endif
PATHFIX_WRKSRC?=	${WRKSRC}

_USES_patch+=	190:pathfix
pathfix:
.if ${USES:Mcmake*}
.for file in ${PATHFIX_CMAKELISTSTXT}
	@${FIND} ${PATHFIX_WRKSRC} -name "${file}" -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|[{]CMAKE_INSTALL_LIBDIR[}]/pkgconfig|{CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|g ; \
		s|[{]CMAKE_INSTALL_DATAROOTDIR[}]/pkgconfig|{CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|g ; \
		s|[{]INSTALL_LIB_DIR[}]/pkgconfig|{CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|g ; \
		s|[{]INSTALL_LIBDIR[}]/pkgconfig|{CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|g ; \
		s|[{]LIB_DESTINATION[}]/pkgconfig|{CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|g ; \
		s|[{]LIB_DIR[}]/pkgconfig|{CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|g ; \
		s|[{]LIB_INSTALL_DIR[}]/pkgconfig|{CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|g ; \
		s|[{]KDE_INSTALL_LIBDIR[}]/pkgconfig|{CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|g ; \
		s|[{]LIBRARY_INSTALL_DIR[}]/pkgconfig|{CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|g ; \
		s|[{]libdir[}]/pkgconfig|{CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|g ; \
		s|lib/pkgconfig|libdata/pkgconfig|g'
.endfor
.else
.for file in ${PATHFIX_MAKEFILEIN}
	@${FIND} ${PATHFIX_WRKSRC} -name "${file}" -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/locale|(prefix)/share/locale|g ; \
		s|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
		s|[(]LIBDIR[)]/pkgconfig|(PREFIX)/libdata/pkgconfig|g ; \
		s|@libdir@/locale|@prefix@/share/locale|g ; \
		s|@libdir@/pkgconfig|@prefix@/libdata/pkgconfig|g ; \
		s|[{]libdir[}]/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
		s|[{]LIBDIR[}]/pkgconfig|(PREFIX)/libdata/pkgconfig|g ; \
		s|[(]datadir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
		s|[{]datadir[}]/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
		s|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
		s|[[:<:]]lib/pkgconfig|libdata/pkgconfig|g; \
		s|[$$][(]localstatedir[)]/scrollkeeper|${SCROLLKEEPER_DIR}|g ; \
		s|[(]libdir[)]/bonobo/servers|(prefix)/libdata/bonobo/servers|g'
.endfor
.endif

.endif
