# Ports collection makefile for:	mercurial
# Date created:				11 July 2005
# Whom:					Andreas Kohn
#
# $FreeBSD$
#

PORTNAME=	mercurial
PORTVERSION=	1.0.1
CATEGORIES=	devel python
MASTER_SITES=	http://www.selenic.com/mercurial/release/

MAINTAINER=	roberto@FreeBSD.org
COMMENT=	A fast, lightweight source control management system

USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes

CONTRIB_FILES=	bash_completion \
		convert-repo \
		darcs2hg.py \
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
		vim/HGAnnotate.vim \
		vim/hg-menu.vim \
		vim/hgcommand.vim \
		vim/patchreview.txt \
		vim/patchreview.vim

DOCS=	CONTRIBUTORS COPYING README doc/*.txt doc/*.html

MAN1=	hg.1
MAN5=	hgignore.5 hgrc.5

PKGMESSAGE=	${WRKDIR}/MESSAGE

post-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}

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
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
