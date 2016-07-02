# Created by: Andreas Kohn
# $FreeBSD$

PORTNAME=	mercurial
PORTVERSION=	3.8.4
CATEGORIES=	devel python
MASTER_SITES=	http://mercurial-scm.org/release/

MAINTAINER=	python@FreeBSD.org
COMMENT=	Fast, lightweight source control management system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	cpe python:2
USE_PYTHON=	distutils

OPTIONS_DEFINE=	CA_BUNDLE DATA DOCS NLS FREEBSD
OPTIONS_DEFAULT=DATA
OPTIONS_SUB=	yes

CA_BUNDLE_DESC=		Install CA Certificates
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
FREEBSD_DESC=		Patches used internally by the FreeBSD Project
FREEBSD_EXTRA_PATCHES=	${FILESDIR}/extra-patch-authormapsuffix
NLS_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-setup.py
NLS_USES=		gettext

CONTRIB_FILES=	bash_completion \
		casesmash.py \
		check-code.py \
		debugcmdserver.py \
		debugshell.py \
		dumprevlog \
		hg-ssh \
		hgk \
		hgsh/Makefile \
		hgsh/hgsh.c \
		mercurial.el \
		mq.el \
		perf.py \
		pylintrc \
		python-hook-examples.py \
		simplemerge \
		tcsh_completion \
		tcsh_completion_build.sh \
		undumprevlog \
		zsh_completion \
		vim/HGAnnotate.vim \
		vim/hg-menu.vim \
		vim/hgcommand.vim \
		vim/hgtest.vim \
		vim/patchreview.txt \
		vim/patchreview.vim
DOCS=		CONTRIBUTORS README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDATA}
SUB_FILES=	pkg-message
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/*.5 ${STAGEDIR}${PREFIX}/man/man5/
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/*.so
	${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/hgext/fsmonitor/pywatchman/*.so
.if ${PORT_OPTIONS:MDATA}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/contrib
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

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
