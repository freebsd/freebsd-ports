# New ports collection makefile for:	ruby
# Date created:		04 September 1997
# Whom:			Eiji-usagi-MATSUmoto <usagi@ruby.club.or.jp>
#
# $FreeBSD$
#

PORTNAME=	ruby${RUBY_R}
PORTVERSION=	${RUBY_PORTVERSION}
CATEGORIES=	lang ruby ipv6
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	stable
DISTNAME=	${RUBY_DISTNAME}
DIST_SUBDIR=	ruby

PATCH_SITES=	${MASTER_SITE_RUBY}
PATCH_SITE_SUBDIR=	snapshots
PATCHFILES=	${RUBY_PATCHFILES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	knu@FreeBSD.org

#USE_BZIP2=	yes

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

USE_AUTOCONF_VER=213
INSTALLS_SHLIB=	yes
WRKSRC=		${RUBY_WRKSRC}
CONFIGURE_ARGS=	${RUBY_CONFIGURE_ARGS} \
		--enable-shared
MAN1=		ruby${_RUBY_SUFFIX}.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
MLINKS=		ruby${_RUBY_SUFFIX}.1 ruby${RUBY_R}.1
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

IRB_WITHOUT_SUFFIX=	${LOCALBASE}/bin/irb
IRB_WITH_SUFFIX=	${IRB_WITHOUT_SUFFIX}${_RUBY_SUFFIX}

post-patch:
	find ${WRKSRC} -name '*.orig' -delete
.for d in Win32API
	${RM} -rf ${WRKSRC}/ext/${d}
.endfor
.for d in gdbm tcltklib tk
	${MV} ${WRKSRC}/ext/${d} ${WRKDIR}/
.endfor

pre-install:
	${RM} -f ${RUBY_WITHOUT_SUFFIX}${RUBY_R} \
		${PREFIX}/man/man1/ruby${RUBY_R}.1 \
		${PREFIX}/man/man1/ruby${RUBY_R}.1.gz \
		${IRB_WITHOUT_SUFFIX}${RUBY_R}

post-install:
.if ${STRIP} == -s
	strip ${RUBY}
.endif
.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
	${MV} -f ${RUBY_WITHOUT_SUFFIX}${RUBY_R} ${RUBY_WITH_SUFFIX}
	${MV} -f ${PREFIX}/man/man1/ruby${RUBY_R}.1 ${PREFIX}/man/man1/ruby${_RUBY_SUFFIX}.1
.endif
	${MV} -f ${IRB_WITHOUT_SUFFIX} ${IRB_WITH_SUFFIX}
	if [ -x ${RUBY_WITHOUT_SUFFIX}${RUBY_DEFAULT_SUFFIX}${RUBY_R} ]; then \
		${LN} -fs ${RUBY_WITHOUT_SUFFIX}${RUBY_DEFAULT_SUFFIX}${RUBY_R} ${RUBY_WITHOUT_SUFFIX}${RUBY_R}; \
		${LN} -fs ruby${RUBY_DEFAULT_SUFFIX}${RUBY_R}.1${MANEXT} ${PREFIX}/man/man1/ruby${RUBY_R}.1${MANEXT}; \
	fi
	if [ -x ${RUBY_WITHOUT_SUFFIX} ]; then \
		${LN} -fs ${IRB_WITHOUT_SUFFIX}${RUBY_DEFAULT_SUFFIX} ${IRB_WITHOUT_SUFFIX}; \
	fi
.if !empty(RUBY_R)
	if [ -x ${RUBY_WITHOUT_SUFFIX}${RUBY_R} ]; then \
		${LN} -fs ${IRB_WITH_SUFFIX} ${IRB_WITHOUT_SUFFIX}${RUBY_R}; \
	fi
.endif
	${LDCONFIG} -m ${LOCALBASE}/lib
	${RUBY_WITH_SUFFIX} ${RUBY_FLAGS} -i -p \
		-e 'if $$. == 1; ' \
		-e ' if /^#!/; ' \
		-e '  sub /^#!\s*\S*(\benv\s+)?\bruby/, "#!${RUBY_WITH_SUFFIX}";' \
		-e ' else;' \
		-e '  $$_ = "#!${RUBY_WITH_SUFFIX}\n" + $$_;' \
		-e ' end;' \
		-e 'end' \
		${IRB_WITH_SUFFIX}
	${CHMOD} ${BINMODE} ${IRB_WITH_SUFFIX}
	${MKDIR} ${RUBY_ELISPDIR}
	${TOUCH} ${RUBY_ELISPDIR}/.keep_me
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
	${INSTALL_DATA} ${WRKSRC}/LEGAL ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${RUBY_DOCDIR}
	${MKDIR} ${RUBY_DOCDIR}/digest
	${INSTALL_DATA} ${WRKSRC}/ext/digest/digest.txt* ${RUBY_DOCDIR}/digest
	${MKDIR} ${RUBY_DOCDIR}/etc
	${INSTALL_DATA} ${WRKSRC}/ext/etc/etc.txt* ${RUBY_DOCDIR}/etc
	${MKDIR} ${RUBY_DOCDIR}/pty
	${INSTALL_DATA} ${WRKSRC}/ext/pty/README* ${RUBY_DOCDIR}/pty
	${MKDIR} ${RUBY_DOCDIR}/readline
	${INSTALL_DATA} ${WRKSRC}/ext/readline/README* ${RUBY_DOCDIR}/readline
	${MKDIR} ${RUBY_DOCDIR}/syslog
	${INSTALL_DATA} ${WRKSRC}/ext/syslog/syslog.txt ${RUBY_DOCDIR}/syslog
	${CP} -R ${WRKSRC}/doc/* ${RUBY_DOCDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

test:
	@(cd ${WRKSRC}; ${MAKE} test)

.include <bsd.port.post.mk>
