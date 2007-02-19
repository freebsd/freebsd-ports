# Ports collection makefile for:	gem_plugin
# Date created:				20 May 2006
# Whom:					Rui Lopes (<rgl ruilopes com>)
#
# $FreeBSD$

PORTNAME=	gem_plugin
PORTVERSION=	0.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=     mongrel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gem Based Plugin System

BUILD_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake
RUN_DEPENDS=	${BUILD_DEPENDS}

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

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
