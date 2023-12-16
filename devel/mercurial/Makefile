PORTNAME=	mercurial
PORTVERSION=	6.6.1
CATEGORIES=	devel python
MASTER_SITES=	https://www.mercurial-scm.org/release/

MAINTAINER=	python@FreeBSD.org
COMMENT=	Fast, lightweight source control management system
WWW=		https://www.mercurial-scm.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe python shebangfix
SHEBANG_FILES=	contrib/hgweb.fcgi hgweb.cgi
USE_PYTHON=	autoplist pep517

OPTIONS_DEFINE=		DATA DOCS NLS FREEBSD
OPTIONS_DEFAULT=	DATA
OPTIONS_SUB=		yes

DATA_SUB_FILES=		pkg-message
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
PORTDOCS=	CONTRIBUTORS README.rst

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} != ${PYTHON_DEFAULT}
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/*.5 ${STAGEDIR}${PREFIX}/share/man/man5/
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ -name '*.so' -exec ${STRIP_CMD} {} +

post-install-DATA-on:
.for d in hgsh vim
	${MKDIR} ${STAGEDIR}${DATADIR}/contrib/${d}
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}/www
.for f in ${CONTRIB_FILES}
	${INSTALL_DATA} ${WRKSRC}/contrib/${f} \
		${STAGEDIR}${DATADIR}/contrib/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/hgweb.cgi ${WRKSRC}/contrib/hgweb.* ${STAGEDIR}${DATADIR}/www

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
