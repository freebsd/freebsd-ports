# New ports collection makefile for:	ruby-devel
# Date created:		6 May 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ruby
PORTVERSION=	${RUBY_PORTVERSION}
CATEGORIES=	lang ruby ipv6
MASTER_SITES=	http://www.ruby-lang.org/~knu/	# ${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	${RUBY_VER}
DISTNAME=	${RUBY_DISTNAME}
DIST_SUBDIR=	ruby

PATCH_SITES=	http://www.ruby-lang.org/~knu/
PATCHFILES=	${RUBY_PATCHFILES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	knu@FreeBSD.org

RUBY_VER=	1.7

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

USE_AUTOCONF=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${RUBY_WRKSRC}
CONFIGURE_ARGS=	--enable-shared
MAN1=		ruby${_RUBY_SUFFIX}.1
MLINKS=		ruby${_RUBY_SUFFIX}.1 ruby.1

.include <bsd.port.pre.mk>

.if !empty(RUBY_SUFFIX)
CONFIGURE_ARGS+=	--program-suffix="${RUBY_SUFFIX}"
.endif

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ipv6
.endif

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

post-install:
.if ${STRIP} == -s
	strip ${RUBY}
.endif
.if empty(RUBY_SUFFIX)
	${MV} -f ${RUBY_WITHOUT_SUFFIX} ${RUBY_WITH_SUFFIX}
	${LN} -fs ${RUBY_WITH_SUFFIX} ${RUBY_WITHOUT_SUFFIX}
	${MV} ${PREFIX}/man/man1/ruby.1 ${PREFIX}/man/man1/ruby${_RUBY_SUFFIX}.1
.else
	${LN} -fs ${RUBY_WITH_SUFFIX} ${RUBY_WITHOUT_SUFFIX}
.endif
	${INSTALL_SCRIPT} ${IRB_WITHOUT_SUFFIX} ${IRB_WITH_SUFFIX}
	${RUBY} ${RUBY_FLAGS} -i -p \
		-e 'if $$. == 1; ' \
		-e ' if /^#!/; ' \
		-e '  sub /^#!\s*\S*(\benv\s+)?\bruby/, "#!${RUBY_WITHOUT_SUFFIX}";' \
		-e ' else;' \
		-e '  $$_ = "#!${RUBY_WITHOUT_SUFFIX}\n" + $$_;' \
		-e ' end;' \
		-e 'end' \
		${IRB_WITHOUT_SUFFIX}
	${RUBY} ${RUBY_FLAGS} -i -p \
		-e 'if $$. == 1; ' \
		-e ' if /^#!/; ' \
		-e '  sub /^#!\s*\S*(\benv\s+)?\bruby/, "#!${RUBY_WITH_SUFFIX}";' \
		-e ' else;' \
		-e '  $$_ = "#!${RUBY_WITH_SUFFIX}\n" + $$_;' \
		-e ' end;' \
		-e 'end' \
		${IRB_WITH_SUFFIX}
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}
	${MKDIR} ${RUBY_EXAMPLESDIR}/curses
	${INSTALL_DATA} ${WRKSRC}/ext/curses/hello.rb ${WRKSRC}/ext/curses/rain.rb ${WRKSRC}/ext/curses/view.rb ${RUBY_EXAMPLESDIR}/curses
	${MKDIR} ${RUBY_EXAMPLESDIR}/pty
	${INSTALL_DATA} ${WRKSRC}/ext/pty/expect_sample.rb ${WRKSRC}/ext/pty/script.rb ${WRKSRC}/ext/pty/shl.rb ${RUBY_EXAMPLESDIR}/pty
	${MKDIR} ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${RUBY_DOCDIR}
	${MKDIR} ${RUBY_DOCDIR}/etc
	${INSTALL_DATA} ${WRKSRC}/ext/etc/etc.txt* ${RUBY_DOCDIR}/etc
	${MKDIR} ${RUBY_DOCDIR}/md5
	${INSTALL_DATA} ${WRKSRC}/ext/md5/md5.txt* ${RUBY_DOCDIR}/md5
	${MKDIR} ${RUBY_DOCDIR}/pty
	${INSTALL_DATA} ${WRKSRC}/ext/pty/README* ${RUBY_DOCDIR}/pty
	${MKDIR} ${RUBY_DOCDIR}/readline
	${INSTALL_DATA} ${WRKSRC}/ext/readline/README ${RUBY_DOCDIR}/readline
	${CP} -R ${WRKSRC}/doc/* ${RUBY_DOCDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

test:
	@(cd ${WRKSRC}; ${MAKE} test)

.include <bsd.port.post.mk>
