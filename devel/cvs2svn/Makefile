# New ports collection makefile for:	cvs2svn
# Date created:		1 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	cvs2svn
PORTVERSION=	2.1.1
CATEGORIES=	devel
MASTER_SITES=	http://cvs2svn.tigris.org/files/documents/1462/42521/

MAINTAINER=	pgollucci@p6m7g8.com
COMMENT=	CVS to Subversion Repository Converter

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gdbm.so:${PORTSDIR}/databases/py-gdbm
RUN_DEPENDS=	${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion \
		${LOCALBASE}/bin/git:${PORTSDIR}/devel/git \
		${PYTHON_SITELIBDIR}/gdbm.so:${PORTSDIR}/databases/py-gdbm

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

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

.include <bsd.port.mk>
