# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	io-like
PORTVERSION=	0.3.0.20130301
CATEGORIES=	devel rubygems
MASTER_SITES=	LOCAL/tota/${PORTNAME}
PKGNAMEPREFIX=	rubygem-

MAINTAINER=	tota@FreeBSD.org
COMMENT=	The interface of IO objects to classes providing a few simple methods

LICENSE=	RUBY
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUBYGEMBIN}:devel/ruby-gems \
		${LOCALBASE}/bin/rake:devel/rubygem-rake
RUN_DEPENDS=	${RUBYGEMBIN}:devel/ruby-gems

USE_RUBY=	yes
NO_ARCH=	yes

GEMS_BASE_DIR=	lib/ruby/gems/${RUBY_VER}
GEMS_DIR=	${GEMS_BASE_DIR}/gems
DOC_DIR=	${GEMS_BASE_DIR}/doc
CACHE_DIR=	${GEMS_BASE_DIR}/cache
SPEC_DIR=	${GEMS_BASE_DIR}/specifications
GEM_NAME=	${PORTNAME}-${PORTVERSION:C/(\.[0-9]+)$//}
GEM_LIB_DIR=	${GEMS_DIR}/${GEM_NAME}
GEM_DOC_DIR=	${DOC_DIR}/${GEM_NAME}
GEM_SPEC=	${SPEC_DIR}/${GEM_NAME}.gemspec
GEM_CACHE=	${CACHE_DIR}/${GEM_NAME}.gem

PLIST_SUB+=	PORTVERSION="${PORTVERSION}" \
		REV="${RUBY_GEM}" \
		GEMS_BASE_DIR="lib/ruby/gems/${RUBY_VER}" \
		GEMS_DIR="${GEMS_DIR}" \
		DOC_DIR="${DOC_DIR}" \
		CACHE_DIR="${CACHE_DIR}" \
		SPEC_DIR="${SPEC_DIR}" \
		PORT="${PORTNAME}-${PORTVERSION}" \
		GEM_NAME="${GEM_NAME}" \
		GEM_LIB_DIR="${GEM_LIB_DIR}" \
		GEM_DOC_DIR="${GEM_DOC_DIR}" \
		GEM_SPEC="${GEM_SPEC}" \
		GEM_CACHE="${GEM_CACHE}" \
		EXTRACT_SUFX=".gem"

RUBYGEMBIN=	${LOCALBASE}/bin/gem${RUBY_VER:S/.//}
RAKE_BIN=	${LOCALBASE}/bin/rake

GEMFILES=	${GEM_NAME}.gem

RUBYGEM_ARGS=-l --no-update-sources --no-ri --install-dir ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER} --ignore-dependencies --bindir=${STAGEDIR}${PREFIX}/bin

WRKSRC=	${WRKDIR}/${PORTNAME}-ruby-1.9-temp

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	rubygem-allison>=0:devel/rubygem-allison
DOCS_VARS_OFF=		RUBYGEM_ARGS+=--no-rdoc

post-patch:
.for l in 1.8.6 1.8.7 1.9.2 1.9.3
	@${ECHO} lib/io/like-${l}.rb >> ${WRKSRC}/MANIFEST
.endfor
.for f in likestringio.rb rot13filter.rb
	@${RUBY} -i -pe "sub %r|((\s*)require 'io/like')|, %Q|\\\2require 'rubygems'\n\\\1|" ${WRKSRC}/examples/${f}
.endfor

do-build:
	@cd ${BUILD_WRKSRC} && ${RAKE_BIN}

do-install:
	@(cd ${INSTALL_WRKSRC}; ${SETENV} ${GEM_ENV} ${RUBYGEMBIN} install ${RUBYGEM_ARGS} pkg/${GEMFILES} -- --build-args ${CONFIGURE_ARGS})
	@${RM} -r ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR}/build_info
	@${RMDIR} ${STAGEDIR}/${PREFIX}/${GEMS_BASE_DIR}/extensions

post-install:
	@${ECHO} ${GEM_CACHE} >> ${TMPPLIST}
	@${ECHO} ${GEM_SPEC} >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR} -type f -print | ${SED} -E -e \
		's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST}
	@${ECHO} "@dir ${DOC_DIR}" >> ${TMPPLIST}

post-install-DOCS-on:
	@${FIND} -ds ${STAGEDIR}${PREFIX}/${GEM_DOC_DIR} -type f -print | ${SED} -E -e \
		's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST}

.include <bsd.port.mk>
