# Created by: MANTANI Nobutaka <nobutaka@nobutaka.com>
# $FreeBSD$

PORTNAME=	migemo
PORTVERSION=	0.40
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	japanese elisp
MASTER_SITES=	http://0xcc.net/migemo/ \
		${MASTER_SITE_LOCAL:S/$/:skkdic/}
MASTER_SITE_SUBDIR=	nobutaka/:skkdic
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SKKDIC_FILE}.bz2:skkdic
DIST_SUBDIR=	migemo
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT?=	Japanese incremental search tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

.if !defined(SLAVE_PORT)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile.am \
		${FILESDIR}/extra-patch-configure.in
PLIST_SUB=	MIGEMO="" ELISP="@comment "
.endif

USE_RUBY=	yes
USE_AUTOTOOLS=	automake14 autoconf213
BUILD_DEPENDS+=	${RUBY_SITELIBDIR}/romkan.rb:${PORTSDIR}/japanese/ruby-romkan \
		${RUBY_SITELIBDIR}/bsearch.rb:${PORTSDIR}/devel/ruby-bsearch
RUN_DEPENDS+=	${RUBY_SITELIBDIR}/romkan.rb:${PORTSDIR}/japanese/ruby-romkan \
		${RUBY_SITELIBDIR}/bsearch.rb:${PORTSDIR}/devel/ruby-bsearch

CONFIGURE_ARGS+=--with-rubydir=${RUBY_SITELIBDIR}
MAKE_JOBS_UNSAFE=	yes

SHEBANG_FILES=	migemo migemo-client migemo-grep migemo-server

SKKDIC_FILE=	SKK-JISYO.L-20110813

NO_STAGE=	yes
.include <bsd.port.pre.mk>

EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-Makefile.am.ruby19 \
		${PATCHDIR}/extra-patch-configure.in.ruby19 \
		${PATCHDIR}/extra-patch-genchars.sh \
		${PATCHDIR}/extra-patch-migemo \
		${PATCHDIR}/extra-patch-migemo-cache.rb \
		${PATCHDIR}/extra-patch-migemo-client \
		${PATCHDIR}/extra-patch-migemo-convert.rb \
		${PATCHDIR}/extra-patch-migemo-grep \
		${PATCHDIR}/extra-patch-migemo-index.rb \
		${PATCHDIR}/extra-patch-migemo-server \
		${PATCHDIR}/extra-patch-migemo.rb.in \
		${PATCHDIR}/extra-patch-tests_Makefile.am

.if ${ARCH} == "ia64"
BROKEN=		Does not compile on ia64
.endif

post-extract:
.if ${SLAVE_PORT} == "no"
	${BZIP2_CMD} -cd ${DISTDIR}/${DIST_SUBDIR}/${SKKDIC_FILE}.bz2 > ${WRKSRC}/SKK-JISYO.L
.endif

post-patch:
.if ${SLAVE_PORT} == "no"
	@cd ${WRKSRC} ; \
	for f in ${SHEBANG_FILES} ; do \
	${REINPLACE_CMD} -e 's:#!.*:#!${RUBY} -Ke:' $$f ; \
	done
.endif

post-configure:
.if ${SLAVE_PORT} == "no"
	(cd ${WRKSRC}; ${CAT} SKK-JISYO.L | ${RUBY} -Ke migemo-convert.rb > migemo-dict)
	${CP} ${AUTOMAKE_DIR}/config.guess ${WRKSRC}
	${CP} ${AUTOMAKE_DIR}/config.sub ${WRKSRC}
.endif

post-install:
.if ${SLAVE_PORT} == "yes"
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
