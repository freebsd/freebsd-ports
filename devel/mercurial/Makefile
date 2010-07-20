# Ports collection makefile for:	mercurial
# Date created:				11 July 2005
# Whom:					Andreas Kohn
#
# $FreeBSD$
#

PORTNAME=	mercurial
PORTVERSION=	1.5.4
CATEGORIES=	devel python
MASTER_SITES=	http://mercurial.selenic.com/release/

MAINTAINER=	roberto@FreeBSD.org
COMMENT=	A fast, lightweight source control management system

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif
USE_PYTHON=	2.4+
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	${PORTNAME}
PYDISTUTILS_PKGVERSION=	${PORTVERSION}
PYDISTUTILS_EGGINFO=	${PORTNAME}-${PORTVERSION}-${PYTHON_VERSION:S/thon//}.egg-info

CONTRIB_FILES=	bash_completion \
		convert-repo \
		dumprevlog \
		hg-ssh \
		hgdiff \
		hgk \
		logo-droplets.svg \
		memory.py \
		mercurial.el \
		mergetools.hgrc \
		mq.el \
		perf.py \
		pylintrc \
		python-hook-examples.py \
		rewrite-log \
		sample.hgrc \
		shrink-revlog.py \
		simplemerge \
		tcsh_completion \
		tcsh_completion_build.sh \
		tmplrewrite.py \
		undumprevlog \
		zsh_completion \
		git-viz/git-cat-file \
		git-viz/git-diff-tree \
		git-viz/git-rev-list \
		git-viz/git-rev-tree \
		git-viz/hg-viz \
		hgsh/Makefile \
		hgsh/hgsh.c \
		vim/HGAnnotate.vim \
		vim/hg-menu.vim \
		vim/hgcommand.vim \
		vim/patchreview.txt \
		vim/patchreview.vim

DOCS=	CONTRIBUTORS COPYING README doc/*.txt doc/*.html

MAN1=	hg.1
MAN5=	hgignore.5 hgrc.5

SUB_FILES=	pkg-message

post-patch:
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} '/^build.sub_co.*$$/d' ${WRKSRC}/setup.py
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/*.5 ${PREFIX}/man/man5/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for f in ${DOCS}; do \
		${INSTALL_MAN} ${WRKSRC}/$${f} ${DOCSDIR}; \
	done
.endif
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/contrib
	${MKDIR} ${DATADIR}/contrib/git-viz
	${MKDIR} ${DATADIR}/contrib/hgsh
	${MKDIR} ${DATADIR}/contrib/vim
	for f in ${CONTRIB_FILES}; do \
		${CP} -p ${WRKSRC}/contrib/$${f} ${DATADIR}/contrib/$${f}; \
	done
	${MKDIR} ${DATADIR}/www
	${INSTALL_MAN} ${WRKSRC}/*.cgi ${DATADIR}/www
	${INSTALL_MAN} ${WRKSRC}/contrib/hgwebdir.fcgi ${DATADIR}/www
	${INSTALL_MAN} ${WRKSRC}/contrib/hgwebdir.wsgi ${DATADIR}/www
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
