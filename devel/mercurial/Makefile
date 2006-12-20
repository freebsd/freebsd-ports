# Ports collection makefile for:	mercurial
# Date created:				11 July 2005
# Whom:					Andreas Kohn
#
# $FreeBSD$
#

PORTNAME=	mercurial
PORTVERSION=	0.9.3
CATEGORIES=	devel python
MASTER_SITES=	http://www.selenic.com/mercurial/release/

MAINTAINER=	roberto@FreeBSD.org
COMMENT=	A fast, lightweight source control management system

USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes

CONTRIB_FILES=	bash_completion \
		convert-repo \
		darcs2hg.py \
		favicon.ico \
		hg-ssh \
		hgdiff \
		hgk \
		mercurial.el \
		sample.hgrc \
		tcsh_completion \
		zsh_completion \
		git-viz/git-cat-file \
		git-viz/git-diff-tree \
		git-viz/git-rev-list \
		git-viz/git-rev-tree \
		git-viz/hg-viz \
		hgsh/Makefile \
		hgsh/hgsh.c \
		purge/README \
		purge/purge.py \
		vim/HGAnnotate.vim \
		vim/hg-menu.vim \
		vim/hgcommand.vim \
		vim/patchreview.txt \
		vim/patchreview.vim

PORTDOCS=	CONTRIBUTORS COPYING README doc/*.txt doc/*.html

PKGMESSAGE=	${WRKDIR}/MESSAGE

post-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for f in ${PORTDOCS}; do \
		${INSTALL_MAN} ${WRKSRC}/$${f} ${DOCSDIR}; \
	done
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/contrib
	${MKDIR} ${DATADIR}/contrib/git-viz
	${MKDIR} ${DATADIR}/contrib/hgsh
	${MKDIR} ${DATADIR}/contrib/purge
	${MKDIR} ${DATADIR}/contrib/vim
	for f in ${CONTRIB_FILES}; do \
		${CP} -p ${WRKSRC}/contrib/$${f} ${DATADIR}/contrib/$${f}; \
	done
	${MKDIR} ${DATADIR}/www
	${INSTALL_MAN} ${WRKSRC}/*.cgi ${DATADIR}/www
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
