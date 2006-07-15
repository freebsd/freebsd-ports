# Ports collection makefile for:	tzinfo
# Date created:				9 June 2006
# Whom:					Rui Lopes (rgl ruilopes com)
#
# $FreeBSD$
#

PORTNAME=	tzinfo
PORTVERSION=	0.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	http://rubyforge.org/frs/download.php/10558/

MAINTAINER=	rgl@ruilopes.com
COMMENT=	Daylight-savings aware timezone support for Ruby

BROKEN=		fails to fetch

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		;s,^${GEM_CACHE}$$,%%GEM_CACHE%%,g \
		;s,${GEM_DOC_DIR}(/.+)?$$,%%GEM_DOC_DIR%%\1,g \
		;s,${GEM_LIB_DIR}(/.+)?$$,%%GEM_LIB_DIR%%\1,g \
		;s,^${GEM_SPEC}$$,%%GEM_SPEC%%,g \
		;s,^${GEMS_BASE_DIR}/(.+)$$,\1,g \
		;s,^@dirrm (${SPEC_DIR}|${GEMS_DIR}|lib/ruby).*$$,,g \
		' | ${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
