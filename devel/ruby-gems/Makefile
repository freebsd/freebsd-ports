# New ports collection makefile for:	RubyGems
# Date created:		07 July 2004
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	gems
PORTVERSION=	1.6.2
CATEGORIES=	devel ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	ruby${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Package management framework for the Ruby language

USE_RUBY=	yes
RUBY_SETUP=	setup.rb
RUBY_VER=	1.8

NO_BUILD=	yes

PLIST_SUB+=	DISTNAME="${DISTNAME}"

.if !defined(NOPORTDOCS)
RUBY_SETUP_OPTIONS=
.else
RUBY_SETUP_OPTIONS=	--no-ri --no-rdoc
.endif

GEMS_BASE_DIR=		lib/ruby/gems
GEMS_BASE_DIR_P=	${GEMS_BASE_DIR}
GEMS_VER_DIR=		${GEMS_BASE_DIR}/${RUBY_VER}
GEMS_VER_DIR_P=		${GEMS_BASE_DIR_P}/%%RUBY_VER%%
GEMS_DOC_BASE_DIR=	${GEMS_VER_DIR}/doc
GEMS_DOC_BASE_DIR_P=	${GEMS_VER_DIR_P}/doc
GEMS_DOC_DIR=		${GEMS_DOC_BASE_DIR}/${DISTNAME}
GEMS_DOC_DIR_P=		${GEMS_DOC_BASE_DIR_P}/%%DISTNAME%%

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
IGNORE=	already included in this ruby distribution
.endif

do-install:
	cd ${WRKSRC}; ${RUBY} ${RUBY_SETUP} ${RUBY_SETUP_OPTIONS}

post-install:
	@${MKDIR} ${PREFIX}/${GEMS_DOC_BASE_DIR}/
	@${TOUCH} ${PREFIX}/${GEMS_DOC_BASE_DIR}/.keep_this
	@${LN} -sf ${PREFIX}/bin/gem18 ${PREFIX}/bin/gem

.if !defined(NOPORTDOCS)
	@${FIND} -ds ${PREFIX}/lib/ruby/gems/${RUBY_VER}/doc/${DISTNAME} \
		-type f -print | ${SED} -E -e 's,^${PREFIX}/?,,' >> ${TMPPLIST}
	@${FIND} -ds ${PREFIX}/lib/ruby/gems/${RUBY_VER}/doc/${DISTNAME} \
		 -type d -print | ${SED} -E -e 's,^${PREFIX}/?,@dirrm ,' >> ${TMPPLIST}
.endif
	@${ECHO_CMD} "@unexec rmdir %D/lib/ruby/gems/${RUBY_VER}/doc 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/lib/ruby/gems/${RUBY_VER} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/lib/ruby/gems 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/lib/ruby 2>/dev/null || true" >> ${TMPPLIST}

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	${ECHO} bin/gem > pkg-plist.new
	${ECHO} bin/gem18 >> pkg-plist.new
	${ECHO} bin/update_rubygems18 >> pkg-plist.new
	${ECHO} ${GEMS_VER_DIR_P}/cache/sources-0.0.2.gem >> pkg-plist.new
	${FIND} ${PREFIX}/${GEMS_VER_DIR}/gems/sources-0.0.2 -type f | ${SORT} | ${SED} -e 's,${PREFIX}/${GEMS_VER_DIR},${GEMS_VER_DIR_P},' >> pkg-plist.new
	${ECHO} ${GEMS_VER_DIR_P}/specifications/sources-0.0.2.gemspec >> pkg-plist.new
	${ECHO} %%RUBY_SITELIBDIR%%/rbconfig/datadir.rb >> pkg-plist.new
	${ECHO} %%RUBY_SITELIBDIR%%/rubygems.rb >> pkg-plist.new
	${FIND} ${RUBY_SITELIBDIR}/rubygems -type f | ${SORT} | ${SED} -e 's,${RUBY_SITELIBDIR},%%RUBY_SITELIBDIR%%,' >> pkg-plist.new
	${ECHO} %%RUBY_SITELIBDIR%%/ubygems.rb >> pkg-plist.new
	${FIND} ${PREFIX}/${GEMS_DOC_DIR} -type f | ${SORT} | ${SED} -e 's,${PREFIX}/${GEMS_DOC_DIR},%%PORTDOCS%%${GEMS_DOC_DIR_P},' >> pkg-plist.new

	${FIND} ${RUBY_SITELIBDIR}/rubygems -type d | ${SORT} -r | ${SED} -e 's,${RUBY_SITELIBDIR},@dirrm %%RUBY_SITELIBDIR%%,' >> pkg-plist.new
	${ECHO} @dirrm %%RUBY_SITELIBDIR%%/rbconfig >> pkg-plist.new
	${ECHO} @dirrmtry ${GEMS_VER_DIR_P}/specifications >> pkg-plist.new
	${FIND} ${PREFIX}/${GEMS_VER_DIR}/gems/sources-0.0.2 -type d | ${SORT} -r | ${SED} -e 's,${PREFIX}/${GEMS_VER_DIR},@dirrm ${GEMS_VER_DIR_P},' >> pkg-plist.new
	${ECHO} @dirrmtry ${GEMS_VER_DIR_P}/gems >> pkg-plist.new
	${ECHO} @dirrmtry ${GEMS_VER_DIR_P}/cache >> pkg-plist.new
	${FIND} ${PREFIX}/${GEMS_DOC_DIR} -type d | ${SORT} -r | ${SED} -e 's,${PREFIX}/${GEMS_DOC_DIR},%%PORTDOCS%%@dirrm ${GEMS_DOC_DIR_P},' >> pkg-plist.new
	${ECHO} ${PREFIX}/${GEMS_DOC_BASE_DIR}/.keep_this  >> pkg-plist.new
	${ECHO} @dirrmtry ${GEMS_DOC_BASE_DIR_P} >> pkg-plist.new
	${ECHO} @dirrmtry ${GEMS_VER_DIR_P} >> pkg-plist.new
	${ECHO} @dirrmtry ${GEMS_BASE_DIR_P} >> pkg-plist.new

.include <bsd.port.post.mk>
