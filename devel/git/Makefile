# Created by: Eric Anholt
# $FreeBSD$

PORTNAME=	git
PORTVERSION=	1.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-manpages-${PORTVERSION}${EXTRACT_SUFX}
# We manually extract the htmldocs.
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-manpages-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	wxs@FreeBSD.org
COMMENT?=	Distributed source code management tool

PROJECTHOST=	git-core

CONFLICTS?=	git-subversion-[0-9]*

USERS=	git_daemon
GROUPS=	git_daemon

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

GNU_CONFIGURE=	yes
USES=		gmake shebangfix
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	V=1
USE_OPENSSL=	yes
USE_RC_SUBR=	git_daemon

CONFIGURE_ARGS=	--enable-pthreads=-pthread ac_cv_header_libcharset_h=no

OPTIONS_DEFINE=	GUI SVN GITWEB CONTRIB P4 CVS HTMLDOCS PERL ICONV CURL \
		ETCSHELLS NLS
OPTIONS_DEFAULT=	CONTRIB P4 CVS PERL ICONV CURL ETCSHELLS NLS

GITWEB_DESC=	Install gitweb
CONTRIB_DESC=	Install contributed scripts
P4_DESC=	Enable Perforce support
CVS_DESC=	Enable CVS support
HTMLDOCS_DESC=	Install additional documentation
ETCSHELLS_DESC=	Modify /etc/shells

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
MAKE_ARGS+=	NO_GETTEXT=yes
.endif

# This is intentionally not exposed as an option.
.ifndef (WITH_DEBUG)
ALL_TARGET=	all strip
.endif

.if ${PORT_OPTIONS:MP4} || ${PORT_OPTIONS:MCONTRIB}
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON_VER=${PYTHON_VER} PYTHON=""
CONFIGURE_ARGS+=	--with-python=${PYTHON_CMD}
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
MAKE_ENV+=	PERL_PATH=${PERL}
BUILD_DEPENDS+=	p5-Error>=0:${PORTSDIR}/lang/p5-Error
RUN_DEPENDS+=	p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-Net-SMTP-SSL>=0:${PORTSDIR}/mail/p5-Net-SMTP-SSL
PLIST_SUB+=	PERLSUB=""
.else
MAKE_ARGS+=	NO_PERL=1
PLIST_SUB+=	PERLSUB="@comment "
.endif

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
.else
MAKE_ARGS+=	NO_ICONV=1
.endif

.if ${PORT_OPTIONS:MCURL}
MAKE_ENV+=	CURLDIR=${LOCALBASE}
BUILD_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
LIB_DEPENDS+=	libexpat.so:${PORTSDIR}/textproc/expat2
PLIST_SUB+=	CURL=""
.else
MAKE_ARGS+=	NO_CURL=1 \
		NO_EXPAT=1
PLIST_SUB+=	CURL="@comment "
.endif

# Always fetch the htmldocs distfile in maintainer mode.
# Always include it when building distinfo (makesum)
.if ${PORT_OPTIONS:MHTMLDOCS} || make(makesum) || (defined(MAINTAINER_MODE) && make(fetch))
DISTFILES+=	${PORTNAME}-htmldocs-${PORTVERSION}${EXTRACT_SUFX}
PLIST_SUB+=	HTMLDOCS=""
.else
PLIST_SUB+=	HTMLDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MGUI}
USES+=		tk
PLIST_SUB+=	GUI=""
MAKE_ARGS+=	TCL_PATH=${TCLSH} TCLTK_PATH=${WISH}
.else
RMMAN1+=	git-citool.1 \
		git-gui.1 \
		gitk.1
PLIST_SUB+=	GUI="@comment "
MAKE_ARGS+=	NO_TCLTK=yes
.endif

# While this port does not explicity honor WITH_SUBVERSION_VER knob it does
# depend upon devel/p5-subversion, which does honor that knob. If you want
# to have git use devel/subversion16 it will be brought in through
# devel/p5-subversion if you set WITH_SUBVERSION_VER=16. Otherwise
# devel/subversion will be brought in.
.if ${PORT_OPTIONS:MSVN}
RUN_DEPENDS+=	p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-subversion>=0:${PORTSDIR}/devel/p5-subversion
PLIST_SUB+=	SVN=""
.else
PLIST_SUB+=	SVN="@comment "
RMMAN1+=	git-svn.1
.endif

.if ${PORT_OPTIONS:MGITWEB}
PLIST_SUB+=	GITWEB=""
.else
PLIST_SUB+=	GITWEB="@comment "
.endif

.if ${PORT_OPTIONS:MGITWEB} && empty(PORT_OPTIONS:MPERL)
IGNORE=	using GITWEB support requires PERL support
.endif

.if ${PORT_OPTIONS:MCONTRIB}
PLIST_SUB+=	CONTRIB=""
BUILD_DEPENDS+=	xmlto:${PORTSDIR}/textproc/xmlto \
		asciidoc:${PORTSDIR}/textproc/asciidoc \
		${LOCALBASE}/share/xml/docbook/4.5:${PORTSDIR}/textproc/docbook-xml
.else
PLIST_SUB+=	CONTRIB="@comment "
.endif

.if ${PORT_OPTIONS:MP4}
PLIST_SUB+=	P4=""
.else
PLIST_SUB+=	P4="@comment "
.endif

.if ${PORT_OPTIONS:MCVS}
PLIST_SUB+=	CVS=""
RUN_DEPENDS+=	cvsps:${PORTSDIR}/devel/cvsps
.else
PLIST_SUB+=	CVS="@comment "
RMMAN1+=	git-cvsimport.1 \
		git-cvsexportcommit.1 \
		git-cvsserver.1
RMMAN7+=	gitcvs-migration.7
.endif

.if ${PORT_OPTIONS:METCSHELLS}
PLIST_SUB+=	ETCSHELLS=""
.else
PLIST_SUB+=	ETCSHELLS="@comment "
.endif

post-extract:
.if ${PORT_OPTIONS:MHTMLDOCS}
	@${MKDIR} ${WRKDIR}/htmldocs
	@cd ${WRKDIR}/htmldocs && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${PORTNAME}-htmldocs-${PORTVERSION}${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS}
.endif

post-patch:
.for FILE in ${RMMAN1}
	@${RM} ${WRKDIR}/man1/${FILE}
.endfor
.for FILE in ${RMMAN7}
	@${RM} ${WRKDIR}/man7/${FILE}
.endfor
	@${REINPLACE_CMD} -e 's|share/man/man3|man/man3|' ${WRKSRC}/perl/Makefile.PL
.if empty(PORT_OPTIONS:MCVS)
	@${REINPLACE_CMD} -e '/git-cvsexportcommit.perl/d; \
		/git-cvsimport.perl/d; \
		/git-cvsserver.perl/d; \
		/documented,gitcvs-migration/d; \
		s/git-cvsserver//' \
		${WRKSRC}/Makefile
.endif
.if empty(PORT_OPTIONS:MSVN)
	@${REINPLACE_CMD} -e '/git-svn.perl/d' ${WRKSRC}/Makefile
.endif
.if empty(PORT_OPTIONS:MGITWEB)
	@${REINPLACE_CMD} -e '/$$(MAKE) -C gitweb install/d' ${WRKSRC}/Makefile
.endif
.if empty(PORT_OPTIONS:MP4)
	@${REINPLACE_CMD} -e '/^SCRIPT_PYTHON += git-p4.py$$/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/contrib/subtree/git-subtree.sh
.endif

post-build:
.if ${PORT_OPTIONS:MP4} || ${PORT_OPTIONS:MCONTRIB}
	@${FIND} ${WRKSRC} -name "*.bak" -delete
.endif

post-install:
	(cd ${WRKDIR}/man1/ && ${COPYTREE_SHARE} . ${STAGEDIR}${MANPREFIX}/man/man1)
	(cd ${WRKDIR}/man5/ && ${COPYTREE_SHARE} . ${STAGEDIR}${MANPREFIX}/man/man5)
	(cd ${WRKDIR}/man7/ && ${COPYTREE_SHARE} . ${STAGEDIR}${MANPREFIX}/man/man7)
.if ${PORT_OPTIONS:MHTMLDOCS}
	# Manually remove the index.html symlink before installing, and then
	# recreate it after. This is necessary because the distfile is
	# extracted with --no-same-owner. If the distfile is extracted as a
	# non-root user then the symlink will have the incorrect owner.
	${RM} -f ${WRKDIR}/htmldocs/index.html
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/htmldocs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${LN} -s git.html ${STAGEDIR}${DOCSDIR}/index.html
.endif
	-${RM} -f ${STAGEDIR}${PREFIX}/lib/perl5/${PERL_VER}/mach/perllocal.pod
	${MKDIR} ${STAGEDIR}${PREFIX}/share/emacs/site-lisp/git
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/xemacs/site-lisp/git
	${INSTALL_DATA} ${WRKSRC}/contrib/emacs/git.el \
		${STAGEDIR}${PREFIX}/share/emacs/site-lisp/git/
	${INSTALL_DATA} ${WRKSRC}/contrib/emacs/git-blame.el \
		${STAGEDIR}${PREFIX}/share/emacs/site-lisp/git/
	${LN} -sf ${PREFIX}/share/emacs/site-lisp/git/git.el    \
		${STAGEDIR}${PREFIX}/lib/xemacs/site-lisp/git/git.el
	${LN} -sf ${PREFIX}/share/emacs/site-lisp/git/git-blame.el \
		${STAGEDIR}${PREFIX}/lib/xemacs/site-lisp/git/git-blame.el
.if ${PORT_OPTIONS:MCONTRIB}
	@${ECHO_MSG} "===> Installing contributed scripts"
	${MKDIR} ${STAGEDIR}${PREFIX}/share/git-core/contrib
	${CP} -R ${WRKSRC}/contrib/* ${STAGEDIR}${PREFIX}/share/git-core/contrib
	cd ${WRKSRC}/contrib/subtree && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_FLAGS} Makefile ${MAKE_ARGS} install install-doc
.endif
.if ${PORT_OPTIONS:MP4}
	${INSTALL_SCRIPT} ${WRKSRC}/git-p4.py ${STAGEDIR}${PREFIX}/bin/
.endif

.include <bsd.port.mk>
