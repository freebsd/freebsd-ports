# New ports collection makefile for:	ruby
# Date created:		04 September 1997
# Whom:			Eiji-usagi-MATSUmoto <usagi@ruby.club.or.jp>
#
# $FreeBSD$
#

PORTNAME=	ruby
PORTVERSION=	${RUBY_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	lang ruby ipv6
MASTER_SITES=		${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	${MASTER_SITE_SUBDIR_RUBY}
DISTFILES=		${RUBY_DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	ruby

PATCH_SITES=	${MASTER_SITE_RUBY}
PATCH_SITE_SUBDIR=	snapshots
PATCHFILES=	${RUBY_PATCHFILES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	knu@FreeBSD.org
COMMENT=	An object-oriented interpreted scripting language

.if defined(WITH_ONIGURUMA)
PKGNAMESUFFIX=	+oniguruma
BUILD_DEPENDS+=	${NONEXISTENT}:${ONIGURUMA_PORTDIR}:patch
ONIGURUMA_PORTDIR=	${PORTSDIR}/devel/oniguruma
ONIGURUMA_WRKSRC=	`cd ${ONIGURUMA_PORTDIR}; ${MAKE} -V WRKSRC`
PLIST_SUB+=	ONIGURUMA=""
.else
PLIST_SUB+=	ONIGURUMA="@comment "
.endif

# Ruby 1.6 does not support IA64 yet.
ONLY_FOR_ARCHS=		i386
# There are some problems on alpha and sparc64; use 1.8 or later.
ONLY_FOR_ARCHS+=	alpha sparc64

USE_BZIP2=	yes

RUBY_VER=	1.6

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

#USE_AUTOCONF=	yes	# works either with 2.53 or with 2.13
GNU_CONFIGURE=	yes
WRKSRC=		${RUBY_WRKSRC}
CONFIGURE_ARGS=	${RUBY_CONFIGURE_ARGS} \
		--enable-shared

.if defined(DEBUG)
CFLAGS+=	-g
STRIP=		# none
.endif

INSTALLS_SHLIB=	yes
MAN1=		${RUBY_NAME}.1

.include <bsd.port.pre.mk>

MAKE_ARGS=	-j3

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ipv6
.endif

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

INSTALLED_SCRIPTS=	${PREFIX}/bin/irb

OBSOLETED_MODULES=	sha1 \
			shell \
			syslog \
			timex \
			urb \
			uri

post-patch:
	${FIND} ${PATCH_WRKSRC} -name '*.orig' -delete
.for d in Win32API
	${RM} -rf ${BUILD_WRKSRC}/ext/${d}
.endfor
.for d in gdbm tcltklib tk
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
# Link just installed "ruby" to "ruby16", etc.
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
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}
	${MKDIR} ${RUBY_EXAMPLESDIR}/curses
	${INSTALL_DATA} ${WRKSRC}/ext/curses/hello.rb ${WRKSRC}/ext/curses/rain.rb ${WRKSRC}/ext/curses/view.rb ${RUBY_EXAMPLESDIR}/curses
	${MKDIR} ${RUBY_EXAMPLESDIR}/pty
	${INSTALL_DATA} ${WRKSRC}/ext/pty/expect_sample.rb ${WRKSRC}/ext/pty/script.rb ${WRKSRC}/ext/pty/shl.rb ${RUBY_EXAMPLESDIR}/pty
	${INSTALL_DATA} ${WRKSRC}/COPYING* ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LEGAL ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ext/digest/digest.txt* ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ext/etc/etc.txt* ${RUBY_DOCDIR}
	${MKDIR} ${RUBY_DOCDIR}/pty
	${INSTALL_DATA} ${WRKSRC}/ext/pty/README* ${RUBY_DOCDIR}/pty
	${MKDIR} ${RUBY_DOCDIR}/readline
	${INSTALL_DATA} ${WRKSRC}/ext/readline/README* ${RUBY_DOCDIR}/readline
	${INSTALL_DATA} ${WRKSRC}/ext/syslog/syslog.txt ${RUBY_DOCDIR}
	${CP} -R ${WRKSRC}/doc/* ${RUBY_DOCDIR}/
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
