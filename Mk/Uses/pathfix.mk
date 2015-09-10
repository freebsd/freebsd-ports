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

PATHFIX_MAKEFILEIN?=	Makefile.in

_USES_patch+=	190:pathfix
pathfix:
	@${FIND} ${WRKSRC} -name "${PATHFIX_MAKEFILEIN}" -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/locale|(prefix)/share/locale|g ; \
		s|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
		s|[(]LIBDIR[)]/pkgconfig|(PREFIX)/libdata/pkgconfig|g ; \
		s|[{]libdir[}]/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
		s|[{]LIBDIR[}]/pkgconfig|(PREFIX)/libdata/pkgconfig|g ; \
		s|[(]datadir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
		s|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
		s|[$$][(]localstatedir[)]/scrollkeeper|${SCROLLKEEPER_DIR}|g ; \
		s|[(]libdir[)]/bonobo/servers|(prefix)/libdata/bonobo/servers|g'

.endif
