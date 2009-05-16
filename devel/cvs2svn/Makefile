# New ports collection makefile for:	cvs2svn
# Date created:		1 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	cvs2svn
PORTVERSION=	2.2.0
CATEGORIES=	devel
MASTER_SITES=	http://cvs2svn.tigris.org/files/documents/1462/44372/

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	CVS to Subversion Repository Converter

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gdbm.so:${PORTSDIR}/databases/py-gdbm
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

OPTIONS=	SUBVERSION "Build with subversion support" on \
		GIT "Build with git support" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SUBVERSION) && defined(WITHOUT_GIT)
IGNORE=	choose at least subversion, git or both
.endif

.if defined(WITH_SUBVERSION)
RUN_DEPENDS+=	${LOCALBASE}/bin/svn:${PORTSDIR}/devel/py-subversion
.endif

.if defined(WITH_GIT)
RUN_DEPENDS+=	${LOCALBASE}/bin/git:${PORTSDIR}/devel/git

MAKE_JOBS_SAFE=  yes
.endif

MAN1=		cvs2svn.1

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

post-install:
	${INSTALL_MAN} ${WRKSRC}/cvs2svn.1 ${PREFIX}/man/man1/

.include <bsd.port.post.mk>
