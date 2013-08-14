# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	cvs2svn
PORTVERSION=	2.4.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://cvs2svn.tigris.org/files/documents/1462/49237/ \
		LOCAL/ohauer

# 2.4.0 -> svn r5392
PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	ohauer
PATCHREV=	5406
PATCHFILES=	${PORTNAME}-${PORTVERSION}-r${PATCHREV}.diff.bz2

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	CVS to Subversion Repository Converter

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdbm>0:${PORTSDIR}/databases/py-gdbm
RUN_DEPENDS:=	${BUILD_DEPENDS}


USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes

OPTIONS_MULTI=		SCM
OPTIONS_MULTI_SCM=	SUBVERSION GIT BAZAAR
OPTIONS_DEFAULT=	SUBVERSION

SUBVERSION_DESC=	Build with subversion support
GIT_DESC= 		Build with git support
BAZAAR_DESC= 		Build with Bazaar support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSUBVERSION}
RUN_DEPENDS+=	${LOCALBASE}/bin/svn:${PORTSDIR}/devel/py-subversion
.endif

.if ${PORT_OPTIONS:MGIT}
RUN_DEPENDS+=	${LOCALBASE}/bin/git:${PORTSDIR}/devel/git
.endif

.if ${PORT_OPTIONS:MBAZAAR}
RUN_DEPENDS+=	${LOCALBASE}/bin/bzr:${PORTSDIR}/devel/bzr
.endif

MAN1=		cvs2svn.1 \
		cvs2git.1 \
		cvs2bzr.1

PORTDOCS=	design-notes.txt making-releases.txt revision-reader.txt \
		  symbol-notes.txt cvs2bzr.html cvs2git.html cvs2svn.html \
		  faq.html features.html index.html issue_tracker.html \
		  project_license.html project_tools.html

# The only thing different in this target vs. the one found in bsd.port.mk
# is that the extract command exit code is ignored.  tar exits with status
# 1 because the distfile contains a symlink that points nowhere.
do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@-for f in ${EXTRACT_ONLY}; do \
		if ! (cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$f ${EXTRACT_AFTER_ARGS});\
		then \
			exit 1; \
		fi; \
	done

post-build:
		cd ${WRKSRC} && make man

post-install:
	@${INSTALL_MAN} ${WRKSRC}/cvs2svn.1 ${PREFIX}/man/man1/
	@${INSTALL_MAN} ${WRKSRC}/cvs2git.1 ${PREFIX}/man/man1/
	@${INSTALL_MAN} ${WRKSRC}/cvs2bzr.1 ${PREFIX}/man/man1/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/design-notes.txt ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/making-releases.txt ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/revision-reader.txt ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/symbol-notes.txt ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/www/cvs2bzr.html ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/www/cvs2git.html ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/www/cvs2svn.html ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/www/faq.html ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/www/features.html ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/www/index.html ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/www/issue_tracker.html ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/www/project_license.html ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/www/project_tools.html ${DOCSDIR}/
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/cvs2bzr-example.options ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/cvs2git-example.options ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/cvs2hg-example.options ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/cvs2svn-example.options ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
