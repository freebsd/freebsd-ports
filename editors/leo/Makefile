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
PORTEPOCH=	0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alane@freebsd.org

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_ZIP=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

PLIST=${WRKDIR}/plist
INSTALL_DIR=${LOCALBASE}/share

CPIO?=	/usr/bin/cpio
SORT?=	/usr/bin/sort

do-install:
	cd ${WRKDIR}; ${FIND} ${DISTNAME} \
		| ${CPIO} -pdmv -R ${LIBOWN}:${LIBGRP} ${INSTALL_DIR}
	cd ${LOCALBASE}; ${FIND} share/${DISTNAME} -type f \
		| ${XARGS} ${CHMOD} ${LIBMODE}
	cd ${LOCALBASE}; ${FIND} share/${DISTNAME} -type d \
		| ${XARGS} ${CHMOD} ${BINMODE}
	${SED} -e 's|@DISTNAME@|${DISTNAME}|'	\
		-e 's|@LOCALBASE@|${LOCALBASE}|'\
		<${FILESDIR}/leo.in >${LOCALBASE}/bin/leo
	${CHMOD} ${BINMODE} ${LOCALBASE}/bin/leo
	${CHOWN} ${BINOWN}:${BINGRP} ${LOCALBASE}/bin/leo
	${ECHO_CMD} "bin/leo" >${PLIST}
	cd ${LOCALBASE}; ${FIND} share/${DISTNAME} -type f \
		| ${SORT} >>${PLIST}
	cd ${LOCALBASE}; ${FIND} share/${DISTNAME} -type d \
		| ${SORT} -r | ${SED} -e 's|^|@dirrm |' >>${PLIST}

.include <bsd.port.post.mk>

#EOF
