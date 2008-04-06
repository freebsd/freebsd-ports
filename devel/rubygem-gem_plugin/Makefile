# Ports collection makefile for:	gem_plugin
# Date created:				20 May 2006
# Whom:					Rui Lopes (<rgl ruilopes com>)
#
# $FreeBSD$

PORTNAME=	gem_plugin
PORTVERSION=	0.2.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=     mongrel

MAINTAINER=	ports@logvinov.com
COMMENT=	Gem Based Plugin System

RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		;s,^${CACHE_DIR}(/.+)$$,%%CACHE_DIR%%\1,g \
		;s,${GEM_DOC_DIR}(/.+)?$$,%%GEM_DOC_DIR%%\1,g \
		;s,${GEM_LIB_DIR}(/.+)?$$,%%GEM_LIB_DIR%%\1,g \
		;s,^${SPEC_DIR}(/.+)$$,%%SPEC_DIR%%\1,g \
		;s,^${GEMS_BASE_DIR}/(.+)$$,\1,g \
		;s,^@dirrm (${SPEC_DIR}|${GEMS_DIR}|lib/ruby).*$$,,g \
		' | ${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.mk>
