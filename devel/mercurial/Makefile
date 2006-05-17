# Ports collection makefile for:	mercurial
# Date created:				11 July 2005
# Whom:					Andreas Kohn
#
# $FreeBSD$
#

PORTNAME=	mercurial
PORTVERSION=	0.9
CATEGORIES=	devel python
MASTER_SITES=	http://www.selenic.com/mercurial/release/

MAINTAINER=	roberto@FreeBSD.org
COMMENT=	A fast, lightweight source control management system

USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes

CONTRIB_FILES=	bash_completion \
		convert-repo \
		favicon.ico \
		hg-menu.vim \
		hg-ssh \
		hgdiff \
		hgk \
		hgk.py \
		mercurial.el \
		tcsh_completion \
		zsh_completion

PORTDOCS=	CONTRIBUTORS COPYING README *.txt doc/*.txt

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
	for f in ${CONTRIB_FILES}; do \
		${CP} -p ${WRKSRC}/contrib/$${f} ${DATADIR}/contrib; \
	done
	${MKDIR} ${DATADIR}/www
	${INSTALL_MAN} ${WRKSRC}/*.cgi ${DATADIR}/www
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
