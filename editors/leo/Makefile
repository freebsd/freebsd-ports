# ex:ts=8
#
# New ports collection makefile for:	leo
# Date created:			2002/11/17
# Whom:				Alan Eldridge <ports@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	leo
PORTVERSION=	3.9
PORTREVISION=	0
PORTEPOCH=	0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}.zip ${SBOOKFILE} ${EXAMPLESFILES} ${WEBDOCSFILE}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	alane@freebsd.org

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_ZIP=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

ICONSDIR=	${LOCALBASE}/share/icons
DESKTOPDIR=	${LOCALBASE}/share/applnk

SBOOK=		SbooksLeo
SBOOKFILE=	${SBOOK}.zip
SBOOKDIR=	${DOCSDIR}/${SBOOK}

EXAMPLES=	cweb.leo noweb.leo python.leo tkinter.leo
EXAMPLESFILES=	${EXAMPLES:S|leo$|leo.zip|}

WEBDOCS=	LeoWeb
WEBDOCSFILE=	leodocs.zip
WEBDOCSDIR=	${DOCSDIR}/${WEBDOCS}

PLIST=		${WRKDIR}/plist

BINDIR=		${PREFIX}/bin
DATADIR=	${PREFIX}/share
ETCDIR=		${PREFIX}/etc
LIBDIR=		${PREFIX}/lib
PKGDATADIR=	${DATADIR}/${DISTNAME}

BIN_SUBDIR=		${BINDIR:S|^${PREFIX}/||}
DATA_SUBDIR=		${DATADIR:S|^${PREFIX}/||}
DOCS_SUBDIR=		${DOCSDIR:S|^${PREFIX}/||}
ETC_SUBDIR=		${ETCDIR:S|^${PREFIX}/||}
EXAMPLES_SUBDIR=	${EXAMPLESDIR:S|^${PREFIX}/||}
LIB_SUBDIR=		${LIBDIR:S|^${PREFIX}/||}
PKGDATA_SUBDIR=		${PKGDATADIR:S|^${PREFIX}/||}

.if defined(NOPORTDOCS)
ALL_SUBDIRS=	${PKGDATA_SUBDIR}
.else
ALL_SUBDIRS=	${PKGDATA_SUBDIR} ${DOCS_SUBDIR} ${EXAMPLES_SUBDIR}
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
	${MKDIR} ${SBOOKDIR}
	cd ${WRKDIR}/${SBOOK}; ${FIND} . \
		| ${CPIO} -pdmv -R ${DOCOWN}:${DOCGRP} ${SBOOKDIR}
# install web docs
	${MKDIR} ${WEBDOCSDIR}
	cd ${WRKDIR}/${WEBDOCS}; ${FIND} . \
		| ${CPIO} -pdmv -R ${DOCOWN}:${DOCGRP} ${WEBDOCSDIR}
# fix docs perms
	${FIND} ${DOCSDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${DOCMODE}
# install examples
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKDIR}; ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.endif # !defined(NOPORTDOCS)
# fix dir perms
	cd ${PREFIX}; ${FIND} ${ALL_SUBDIRS} -type d -print0 \
		| ${XARGS} -0 ${CHMOD} ${BINMODE}
# create start script
	${SED} -e 's|@PKGDATADIR@|${PKGDATADIR}|' \
		<${FILESDIR}/leo.in >${BINDIR}/leo
	${CHMOD} ${BINMODE} ${BINDIR}/leo
	${CHOWN} ${BINOWN}:${BINGRP} ${BINDIR}/leo
# build plist: bin
	${ECHO_CMD} "${BIN_SUBDIR}/leo" >${PLIST}
# build plist: files
	cd ${PREFIX}; ${FIND} ${ALL_SUBDIRS} -type f \
		| ${SORT} >>${PLIST}
# build plist: dirs
	cd ${PREFIX}; ${FIND} ${ALL_SUBDIRS} -type d \
		| ${SORT} -r | ${SED} -e 's|^|@dirrm |' >>${PLIST}

.include <bsd.port.post.mk>
#EOF
