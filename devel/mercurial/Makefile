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

SHAREDDIR=	${PREFIX}/share/${PORTNAME}
DOCSDIR=	${SHAREDDIR}/doc
CONTRIBDIR=	${SHAREDDIR}/contrib
WWWDIR=		${SHAREDDIR}/www

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

PKGMESSAGE=	${WRKDIR}/MESSAGE

post-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}

post-install:
	${MKDIR} ${SHAREDDIR}
	${INSTALL_DATA} ${WRKSRC}/CONTRIBUTORS ${SHAREDDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${SHAREDDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${SHAREDDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${SHAREDDIR}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
	${MKDIR} ${CONTRIBDIR}
	for f in ${CONTRIB_FILES}; do \
		${CP} -p ${WRKSRC}/contrib/$${f} ${CONTRIBDIR} \
	done
	${MKDIR} ${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/*.cgi ${WWWDIR}
        @${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
