# ex:ts=8
#
# New ports collection makefile for:	leo
# Date created:			2002/11/17
# Whom:				Alan Eldridge <ports@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	leo
PORTVERSION=	3.8
PORTREVISION=	1
PORTEPOCH=	0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME} SbooksLeo

MAINTAINER=	alane@freebsd.org

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_ZIP=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

SBOOKNAME=	SbooksLeo
TUTORIALDIR=	${DOCSDIR}/${SBOOKNAME}

PLIST=		${WRKDIR}/plist

DATADIR=	${PREFIX}/share
PKGDATADIR=	${DATADIR}/${DISTNAME}

DOCS_SUBDIR=	${DOCSDIR:S|^${PREFIX}/||}
PKGDATA_SUBDIR=	${PKGDATADIR:S|^${PREFIX}/||}

.if defined(NOPORTDOCS)
ALL_SUBDIRS=	${PKGDATA_SUBDIR}
.else
ALL_SUBDIRS=	${PKGDATA_SUBDIR} ${DOCS_SUBDIR}
.endif # defined(NOPORTDOCS)

CPIO?=	/usr/bin/cpio
SORT?=	/usr/bin/sort

do-install:
# install dist
	${MKDIR} ${PKGDATADIR}
	cd ${WRKDIR}; ${FIND} ${DISTNAME} \
		| ${CPIO} -pdmv -R ${LIBOWN}:${LIBGRP} ${DATADIR}
# fix dist perms
	${FIND} ${PKGDATADIR} -type f | ${XARGS} ${CHMOD} ${LIBMODE}
.if !defined(NOPORTDOCS)
# install tutorial
	${MKDIR} ${TUTORIALDIR}
	cd ${WRKDIR}/${SBOOKNAME}; ${FIND} . \
		| ${CPIO} -pdmv -R ${DOCOWN}:${DOCGRP} ${TUTORIALDIR}
# fix docs perms
	${FIND} ${DOCSDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${DOCMODE}
.endif # !defined(NOPORTDOCS)
# fix dir perms
	cd ${PREFIX}; ${FIND} ${ALL_SUBDIRS} -type d -print0 \
		| ${XARGS} -0 ${CHMOD} ${BINMODE}
# create start script
	${SED} -e 's|@PKGDATADIR@|${PKGDATADIR}|' \
		<${FILESDIR}/leo.in >${LOCALBASE}/bin/leo
	${CHMOD} ${BINMODE} ${LOCALBASE}/bin/leo
	${CHOWN} ${BINOWN}:${BINGRP} ${LOCALBASE}/bin/leo
# build plist: bin
	${ECHO_CMD} "bin/leo" >${PLIST}
# build plist: files
	cd ${PREFIX}; ${FIND} ${ALL_SUBDIRS} -type f \
		| ${SORT} >>${PLIST}
# build plist: dirs
	cd ${PREFIX}; ${FIND} ${ALL_SUBDIRS} -type d \
		| ${SORT} -r | ${SED} -e 's|^|@dirrm |' >>${PLIST}

.include <bsd.port.post.mk>
#EOF
