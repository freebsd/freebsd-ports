PORTREVISION=	2

MAINTAINER=	michaelo@apache.org
COMMENT=	Apache Subversion is a full-featured version control system
WWW=		https://subversion.apache.org/

CONFLICTS_INSTALL=	subversion-lts

USE_RC_SUBR=	svnserve

PORTDOCS=	BUGS CHANGES COMMITTERS INSTALL README

OPTIONS_DEFINE=	\
		DOCS		\
		GPG_AGENT 	\
		HOOKS		\
		NLS		\
		SASL		\
		SERF		\
		SVNSERVE_WRAPPER\
		TOOLS

OPTIONS_DEFAULT=GPG_AGENT SERF SVNSERVE_WRAPPER

GPG_AGENT_DESC=		Enable GPG agent credential cache
HOOKS_DESC=		Install server-side hook script examples
SERF_DESC=		WebDAV/Delta-V (HTTP/HTTPS) repo access module
SVNSERVE_WRAPPER_DESC=	Enable svnserve wrapper (umask setter)
TOOLS_DESC=		Install several tools

USES+=			shebangfix
python_OLD_CMD+=	"/bin/env python"
SHEBANG_REGEX=		./tools/.*

.include "Makefile.common"

USERS=		svn
GROUPS=		svn

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS+=	--without-swig-perl \
			--without-swig-python \
			--without-swig-ruby \
			--without-gnome-keyring \
			--without-kwallet \
			--with-apxs=no

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
TEST_TARGET=	check

.if ${PORT_OPTIONS:MSVNSERVE_WRAPPER}
SVNSERVE_EXT=	.bin
.else
SVNSERVE_EXT=
.endif
SUB_LIST+=	SVNSERVE_EXT=${SVNSERVE_EXT}

BINS_TO_STRIP=	svn svnadmin svnauthz svnauthz-validate svnbench svndumpfilter \
		svnfsfs svnlook svnmucc svnrdump svnserve${SVNSERVE_EXT} \
		svnsync svnversion

TOOLS_TO_STRIP=	svn-mergeinfo-normalizer svn-populate-node-origins-index \
		svnconflict svndiff svndiff3 svndiff4 svnraisetreeconflict

post-patch-SVNSERVE_WRAPPER-on:
# the real svnserve binary installs as svnserve.bin so bin/svnserve can be
# the umask-setting wrapper script instead; build.conf has no per-target
# install-name override, so rename it here, after Makefile.common's
# post-patch has (re)generated build-outputs.mk from the patched build.conf
	${REINPLACE_CMD} -e 's#(bindir)/svnserve$$(EXEEXT)#(bindir)/svnserve.bin$$(EXEEXT)#' \
		${WRKSRC}/build-outputs.mk

post-configure:
# security/subversion-gnome-keyring provides the library for
# --with-gnome-keyring (SVN_HAVE_LIBSECRET), not the legacy
# --with-old-gnome-keyring (SVN_HAVE_GNOME_KEYRING)
	${REINPLACE_CMD} -E 's%.*#undef SVN_HAVE_LIBSECRET.*%#define SVN_HAVE_LIBSECRET 1%' ${WRKSRC}/subversion/svn_private_config.h

post-build-TOOLS-on:
	${MAKE} -C ${WRKSRC} tools ${MAKE_ARGS}

post-install:
	for F in ${BINS_TO_STRIP} ; do \
	 ${STRIP_CMD} "${STAGEDIR}${PREFIX}/bin/$${F}" ; \
	done
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/xslt
	${INSTALL_DATA} ${WRKSRC}/tools/xslt/svnindex.css ${WRKSRC}/tools/xslt/svnindex.xsl \
		${STAGEDIR}${DATADIR}/xslt
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/tools/client-side/bash_completion \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/svn
# bash_completion defines completions for svn, svnadmin, svndumpfilter,
# svnlook, svnsync, and svnversion; the loader looks up one file per
# command name, so symlink the other five to the real file
.for cmd in svnadmin svndumpfilter svnlook svnsync svnversion
	${LN} -sf svn ${STAGEDIR}${PREFIX}/share/bash-completion/completions/${cmd}
.endfor

post-install-SVNSERVE_WRAPPER-on:
	${INSTALL_SCRIPT} ${FILESDIR}/svnserve.wrapper ${STAGEDIR}${PREFIX}/bin/svnserve

post-install-TOOLS-on:
	${MAKE} -C ${WRKSRC} install-tools ${MAKE_ARGS}
	for F in ${TOOLS_TO_STRIP} ; do \
	 ${STRIP_CMD} "${STAGEDIR}${PREFIX}/bin/$${F}" ; \
	done

HOOKS_EXAMPLES=	commit-access-control.cfg.example mailer/mailer.conf.example \
		svnperms.conf.example validate-files.conf.example

HOOKS_SCRIPTS=	commit-access-control.pl commit-email.rb control-chars.py \
		log-police.py mailer/mailer.py \
		persist-ephemeral-txnprops.py \
		reject-detected-sha1-collisions.sh \
		reject-known-sha1-collisions.sh svn2feed.py svnperms.py \
		validate-extensions.py validate-files.py verify-po.py

post-install-HOOKS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/hook-scripts
.for F in ${HOOKS_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/${F} \
		${STAGEDIR}${DATADIR}/hook-scripts/${F:T}
.endfor
.for F in ${HOOKS_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/hook-scripts/${F} \
		${STAGEDIR}${DATADIR}/hook-scripts/${F:T}
.endfor

.include <bsd.port.post.mk>
