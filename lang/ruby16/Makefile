# New ports collection makefile for:	ruby
# Date created:		04 September 1997
# Whom:			Eiji-usagi-MATSUmoto <usagi@ruby.club.or.jp>
#
# $FreeBSD$
#

PORTNAME=	ruby
PORTVERSION=	${RUBY_PORTVERSION}
CATEGORIES=	lang ruby ipv6
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	${RUBY_VER}
DISTNAME=	${RUBY_DISTNAME}
DIST_SUBDIR=	ruby

PATCH_SITES=	http://www.ruby-lang.org/~knu/
PATCHFILES=	${RUBY_DISTNAME}-${RUBY_SNAPSHOTVERSION}.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

USE_AUTOCONF=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${RUBY_WRKSRC}
CONFIGURE_ARGS=	--enable-shared
MAN1=		ruby${_RUBY_SUFFIX}.1
MLINKS=		ruby${_RUBY_SUFFIX}.1 ruby.1

ELISP_FILES=	inf-ruby.el ruby-mode.el rubydb3x.el

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

.include <bsd.port.pre.mk>

.if !empty(RUBY_SUFFIX)
CONFIGURE_ARGS+=	--program-suffix="${RUBY_SUFFIX}"
.endif

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-patch:
	find ${WRKSRC} -name '*.orig' -delete
.for d in Win32API
	${RM} -rf ${WRKSRC}/ext/${d}
.endfor
.for d in gdbm tcltklib tk
	${MV} ${WRKSRC}/ext/${d} ${WRKDIR}/
.endfor

post-install:
	strip ${RUBY}
.if empty(RUBY_SUFFIX)
	${MV} -f ${RUBY} ${RUBY}${_RUBY_SUFFIX}
	${LN} -fs ${RUBY}${_RUBY_SUFFIX} ${RUBY}
	${MV} ${PREFIX}/man/man1/ruby.1 ${PREFIX}/man/man1/ruby${_RUBY_SUFFIX}.1
.else
	${LN} -fs ${RUBY} ${PREFIX}/bin/ruby
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}
	${MKDIR} ${RUBY_EXAMPLESDIR}/misc
	${INSTALL_DATA} ${WRKSRC}/misc/* ${RUBY_EXAMPLESDIR}/misc
	${MKDIR} ${EMACSLISPDIR}
	${MKDIR} ${XEMACSLISPDIR}
.for f in ${ELISP_FILES}
	${LN} -sf ${RUBY_EXAMPLESDIR}/misc/${f} ${EMACSLISPDIR}/
	${LN} -sf ${RUBY_EXAMPLESDIR}/misc/${f} ${XEMACSLISPDIR}/
.endfor
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
.endif
	@${CAT} ${PKGMESSAGE}

test:
	@(cd ${WRKSRC}; ${MAKE} test)

.include <bsd.port.post.mk>
