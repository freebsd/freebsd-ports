# New ports collection makefile for:	ruby18
# Date created:		6 May 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ruby
PORTVERSION=	${RUBY_PORTVERSION}
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	lang ruby ipv6
MASTER_SITES=		${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	${MASTER_SITE_SUBDIR_RUBY}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	An object-oriented interpreted scripting language

.if defined(WITH_ONIGURUMA)
PKGNAMESUFFIX=	+oniguruma
BUILD_DEPENDS+=	${NONEXISTENT}:${ONIGURUMA_PORTDIR}:patch
ONIGURUMA_PORTDIR=	${PORTSDIR}/devel/oniguruma
ONIGURUMA_WRKSRC=	`cd ${ONIGURUMA_PORTDIR}; ${MAKE} -V WRKSRC`
PLIST_SUB+=	ONIGURUMA=""
.else
PLIST_SUB+=	ONIGURUMA="@comment "
.endif

USE_OPENSSL=	yes

RUBY_VER=	1.8

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

GNU_CONFIGURE=	yes
WRKSRC=		${RUBY_WRKSRC}
CONFIGURE_ARGS=	${RUBY_CONFIGURE_ARGS} \
		--enable-shared --with-openssl-include=${OPENSSLINC}

.if defined(WITH_PTHREADS)
CONFIGURE_ARGS+=--enable-pthread
PKGNAMESUFFIX=	-pthreads
.else
CONFIGURE_ARGS+=--disable-pthread
.endif

.if defined(DEBUG)
CFLAGS+=	-g
STRIP=		# none
.endif

INSTALLS_SHLIB=	yes
MAN1=		${RUBY_NAME}.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502102
EXTRA_PATCHES=	${PATCHDIR}/extrapatch-eval.c
.endif

# Uncomment if it still segfaults with 1.8.4
#.if ${ARCH} == "ia64"
#BROKEN=		"Segfault during build on ia64"
#.endif

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ipv6
.endif

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LIBS="${LIBS} ${PTHREAD_LIBS}"

.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
MLINKS=		${RUBY_NAME}.1 ruby.1
IF_DEFAULT=	""
.else
IF_DEFAULT=	"@comment "
.endif

.if defined(NORUBYLIB)
RUBYLIB=	"@comment "
.else
RUBYLIB=	""
.endif

PLIST_SUB+=	IF_DEFAULT=${IF_DEFAULT} \
		RUBYLIB=${RUBYLIB}

INSTALLED_SCRIPTS=	${PREFIX}/bin/irb \
			${PREFIX}/bin/erb \
			${PREFIX}/bin/h2rb \
			${PREFIX}/bin/rdoc \
			${PREFIX}/bin/ri \
			${PREFIX}/bin/testrb

OBSOLETED_MODULES=	bigfloat \
			csv \
			dl \
			drb \
			erb \
			fileutils \
			gserver \
			openssl \
			optparse \
			racc-runtime \
			rdoc \
			rexml \
			ri \
			sha1 \
			shell \
			soap \
			strscan \
			syslog \
			testunit \
			timex \
			urb \
			uri \
			webrick \
			xmlrpc \
			yaml \
			zlib

pre-everything::
.if !defined(WITH_PTHREADS)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "NOTE:"
	@${ECHO_MSG} "You can enable pthread support by defining WITH_PTHREADS variable,"
	@${ECHO_MSG} "but not recommended since this might break some ruby apps."
	@${ECHO_MSG} ""
.endif

post-extract:
	${MV} ${WRKSRC}/ext/dl/h2rb ${WRKSRC}/bin/

post-patch:
.if ${OSVERSION} < 502102 || ${ARCH} == "sparc64" || ${ARCH} == "alpha"
	${REINPLACE_CMD} -e 's|-lc"|"|g' ${WRKSRC}/configure
.endif
	${REINPLACE_CMD} -e 's|-l$$pthread_lib|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure
	${FIND} ${PATCH_WRKSRC} -name '*.orig' -delete
.for d in Win32API win32ole
	${RM} -rf ${BUILD_WRKSRC}/ext/${d}
.endfor
.for d in gdbm iconv tk
	${MV} ${BUILD_WRKSRC}/ext/${d} ${WRKDIR}/
.endfor

pre-configure:
.if defined(WITH_ONIGURUMA)
	cd ${ONIGURUMA_WRKSRC}; \
	./configure; \
	${MAKE} -f Makefile ${RUBY_VER:S/.//} RUBYDIR=${WRKSRC}
.endif
	${TOUCH} ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
.if defined(STRIP) && ${STRIP} == -s
	${STRIP_CMD} ${RUBY}
.endif
.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
# Link just installed "ruby" to "ruby18", etc.
	${LN} -f ${RUBY_WITH_SUFFIX} ${RUBY_WITHOUT_SUFFIX}
	for f in ${INSTALLED_SCRIPTS}; do \
		${LN} -f $${f}${RUBY_SUFFIX} $${f}; \
	done
.endif
	${LDCONFIG} -m ${PREFIX}/lib
	${MKDIR} ${RUBY_ELISPDIR}
	${TOUCH} ${RUBY_ELISPDIR}/.keep_me.${RUBY_NAME}
	${MKDIR} ${RUBY_EXAMPLESDIR}
	${TOUCH} ${RUBY_EXAMPLESDIR}/.keep_me
	${MKDIR} ${RUBY_DOCDIR}
	${TOUCH} ${RUBY_DOCDIR}/.keep_me
	${MKDIR} ${RUBY_RIDIR}
	${SETENV} LC_TIME=C /bin/date > ${RUBY_RIDIR}/created.rid
	${MKDIR} ${RUBY_SITERIDIR}
	${SETENV} LC_TIME=C /bin/date > ${RUBY_SITERIDIR}/created.rid
.if !defined(NOPORTDOCS)
	${CP} -R ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/
	${MKDIR} ${RUBY_EXAMPLESDIR}/bigdecimal
	${INSTALL_DATA} ${WRKSRC}/ext/bigdecimal/sample/*.rb ${RUBY_EXAMPLESDIR}/bigdecimal
	${MKDIR} ${RUBY_EXAMPLESDIR}/curses
	${INSTALL_DATA} ${WRKSRC}/ext/curses/hello.rb ${WRKSRC}/ext/curses/rain.rb ${WRKSRC}/ext/curses/view.rb ${RUBY_EXAMPLESDIR}/curses
	${MKDIR} ${RUBY_EXAMPLESDIR}/dl
	${INSTALL_DATA} ${WRKSRC}/ext/dl/sample/*.C ${WRKSRC}/ext/dl/sample/*.rb ${RUBY_EXAMPLESDIR}/dl
	${MKDIR} ${RUBY_EXAMPLESDIR}/pty
	${INSTALL_DATA} ${WRKSRC}/ext/pty/expect_sample.rb ${WRKSRC}/ext/pty/script.rb ${WRKSRC}/ext/pty/shl.rb ${RUBY_EXAMPLESDIR}/pty
	${INSTALL_DATA} ${WRKSRC}/COPYING* ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LEGAL ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ext/bigdecimal/bigdecimal_*.html ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ext/digest/digest.txt* ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ext/dl/doc/dl.txt ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ext/enumerator/enumerator.txt ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ext/etc/etc.txt* ${RUBY_DOCDIR}
	${MKDIR} ${RUBY_DOCDIR}/pty
	${INSTALL_DATA} ${WRKSRC}/ext/pty/README* ${RUBY_DOCDIR}/pty
	${MKDIR} ${RUBY_DOCDIR}/readline
	${INSTALL_DATA} ${WRKSRC}/ext/readline/README* ${RUBY_DOCDIR}/readline
	${INSTALL_DATA} ${WRKSRC}/ext/syslog/syslog.txt ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ext/zlib/doc/zlib.rd ${RUBY_DOCDIR}
	${CP} -R ${WRKSRC}/doc/* ${RUBY_DOCDIR}/
	cd ${INSTALL_WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install-doc
.endif
	@${ECHO} "Deinstalling obsoleted packages that are now part of ruby..."
	@cd ${PKG_DBDIR}; for portname in ${OBSOLETED_MODULES}; do \
		for pkg in ${RUBY_PKGNAMEPREFIX}$$portname-*; do \
			if [ -d $$pkg ]; then \
				${ECHO} "---> $$pkg"; \
				${PKG_DELETE} -f $$pkg; \
			fi; \
		done; \
	done
	@${ECHO_CMD} "@exec ${ECHO_CMD} \"Deinstalling obsoleted packages that are now part of ruby...\"" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec cd ${PKG_DBDIR} && for portname in ${OBSOLETED_MODULES}; do for pkg in ${RUBY_PKGNAMEPREFIX}\$$portname-*; do if [ -d \$$pkg ]; then ${ECHO_CMD} \"---> \$$pkg\"; ${PKG_DELETE} -f \$$pkg; fi; done; done" >> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

test:
	@(cd ${WRKSRC}; ${MAKE} test)

.include <bsd.port.post.mk>
