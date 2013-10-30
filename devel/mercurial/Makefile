# Created by: Andreas Kohn
# $FreeBSD$

PORTNAME=	mercurial
PORTVERSION=	2.7.2
CATEGORIES=	devel python
MASTER_SITES=	http://mercurial.selenic.com/release/

MAINTAINER=	python@FreeBSD.org
COMMENT=	Fast, lightweight source control management system

LICENSE=	GPLv2

USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes

OPTIONS_DEFINE=	CA_BUNDLE DATA DOCS NLS
OPTIONS_DEFAULT=DATA
OPTIONS_SUB=	yes
CA_BUNDLE_DESC=	Install CA Certificates

CONTRIB_FILES=	bash_completion \
		casesmash.py \
		check-code.py \
		convert-repo \
		debugcmdserver.py \
		debugshell.py \
		dumprevlog \
		hg-ssh \
		hgfixes/__init__.py \
		hgfixes/fix_bytes.py \
		hgfixes/fix_bytesmod.py \
		hgfixes/fix_leftover_imports.py \
		hgk \
		hgsh/Makefile \
		hgsh/hgsh.c \
		mercurial.el \
		mergetools.hgrc \
		mq.el \
		perf.py \
		pylintrc \
		python-hook-examples.py \
		sample.hgrc \
		simplemerge \
		tcsh_completion \
		tcsh_completion_build.sh \
		tmplrewrite.py \
		undumprevlog \
		zsh_completion \
		vim/HGAnnotate.vim \
		vim/hg-menu.vim \
		vim/hgcommand.vim \
		vim/hgtest.vim \
		vim/patchreview.txt \
		vim/patchreview.vim
DOCS=		CONTRIBUTORS README

CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
NLS_USES=		gettext

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDATA}
SUB_FILES=	pkg-message
.endif

.if !${PORT_OPTIONS:MNLS}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-setup.py
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/*.5 ${STAGEDIR}${PREFIX}/man/man5/
.if ${PORT_OPTIONS:MDATA}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/contrib
	${MKDIR} ${STAGEDIR}${DATADIR}/contrib/hgfixes
	${MKDIR} ${STAGEDIR}${DATADIR}/contrib/hgsh
	${MKDIR} ${STAGEDIR}${DATADIR}/contrib/vim
	for f in ${CONTRIB_FILES}; do \
		${CP} -p ${WRKSRC}/contrib/$${f} ${STAGEDIR}${DATADIR}/contrib/$${f}; \
	done
	${MKDIR} ${STAGEDIR}${DATADIR}/www
	${INSTALL_DATA} ${WRKSRC}/*.cgi ${STAGEDIR}${DATADIR}/www
	${INSTALL_DATA} ${WRKSRC}/contrib/hgweb.fcgi ${STAGEDIR}${DATADIR}/www
	${INSTALL_DATA} ${WRKSRC}/contrib/hgweb.wsgi ${STAGEDIR}${DATADIR}/www
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
