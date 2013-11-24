# Created by: Alexander Novitsky <alecn2002@yandex.ru>
# $FreeBSD$

PORTNAME=	gems
PORTVERSION=	1.8.28
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_RUBYGEMS:S/\/gems\//\/rubygems\//}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Package management framework for the Ruby language

USE_RUBY=	yes
RUBY_SETUP=	setup.rb

NO_BUILD=	yes

PLIST_SUB+=	DISTNAME="${DISTNAME}" \
		RUBY_VER_SHORT="${RUBY_VER_SHORT}"

.if !defined(NOPORTDOCS)
RUBY_SETUP_OPTIONS=	--ri --rdoc
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
RUBY_VER_SHORT=		${RUBY_VER:S/.//}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${PREFIX}/${GEMS_DOC_BASE_DIR}/
	@${TOUCH} ${PREFIX}/${GEMS_DOC_BASE_DIR}/.keep_this
	cd ${WRKSRC}; ${SETENV} ${GEM_ENV} ${RUBY} ${RUBY_SETUP} ${RUBY_SETUP_OPTIONS}

post-install:
	@${LN} -sf ${PREFIX}/bin/gem${RUBY_VER_SHORT} ${PREFIX}/bin/gem

#
# Find all RDOC and RI files
#
.if !defined(NOPORTDOCS)
	@${FIND} -ds ${PREFIX}/${GEMS_DOC_DIR}/ ! -type d | \
	    ${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -ds ${PREFIX}/${GEMS_DOC_DIR}/ -type d -mindepth 1 | \
	    ${SED} -E -e 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${GEMS_DOC_DIR}" >> ${TMPPLIST}
.endif

	@${ECHO_CMD} "@unexec rmdir %D/lib/ruby/gems/${RUBY_VER}/doc 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/lib/ruby/gems/${RUBY_VER} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/lib/ruby/gems 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/lib/ruby 2>/dev/null || true" >> ${TMPPLIST}

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	${ECHO} bin/gem > pkg-plist.new
	${ECHO} bin/gem%%RUBY_VER_SHORT%% >> pkg-plist.new
	${ECHO} %%RUBY_SITELIBDIR%%/gauntlet_rubygems.rb >> pkg-plist.new
	${ECHO} %%RUBY_SITELIBDIR%%/rbconfig/datadir.rb >> pkg-plist.new
	${ECHO} %%RUBY_SITELIBDIR%%/rubygems.rb >> pkg-plist.new
	${FIND} ${RUBY_SITELIBDIR}/rubygems -type f | ${SORT} | ${SED} -e 's,${RUBY_SITELIBDIR},%%RUBY_SITELIBDIR%%,' >> pkg-plist.new
	${ECHO} %%RUBY_SITELIBDIR%%/ubygems.rb >> pkg-plist.new
	${FIND} ${PREFIX}/${GEMS_DOC_DIR} -type f | ${SORT} | ${SED} -e 's,${PREFIX}/${GEMS_DOC_DIR},%%PORTDOCS%%${GEMS_DOC_DIR_P},' >> pkg-plist.new

	${FIND} ${RUBY_SITELIBDIR}/rubygems -type d | ${SORT} -r | ${SED} -e 's,${RUBY_SITELIBDIR},@dirrm %%RUBY_SITELIBDIR%%,' >> pkg-plist.new
	${ECHO} @dirrm %%RUBY_SITELIBDIR%%/rbconfig >> pkg-plist.new
	${ECHO} @dirrmtry ${GEMS_VER_DIR_P}/specifications >> pkg-plist.new
	${ECHO} @dirrmtry ${GEMS_VER_DIR_P}/gems >> pkg-plist.new
	${ECHO} @dirrmtry ${GEMS_VER_DIR_P}/cache >> pkg-plist.new
	${FIND} ${PREFIX}/${GEMS_DOC_DIR} -type d | ${SORT} -r | ${SED} -e 's,${PREFIX}/${GEMS_DOC_DIR},%%PORTDOCS%%@dirrm ${GEMS_DOC_DIR_P},' >> pkg-plist.new
	${ECHO} ${GEMS_DOC_BASE_DIR_P}/.keep_this  >> pkg-plist.new
	${ECHO} @dirrmtry ${GEMS_DOC_BASE_DIR_P} >> pkg-plist.new
	${ECHO} @dirrmtry ${GEMS_VER_DIR_P} >> pkg-plist.new
	${ECHO} @dirrmtry ${GEMS_BASE_DIR_P} >> pkg-plist.new

.include <bsd.port.post.mk>
