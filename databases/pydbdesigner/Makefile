# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	pydbdesigner
# Date created:		2003-01-02
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	pydbdesigner
PORTVERSION=	0.1.3
PORTREVISION=	0
PORTEPOCH=	0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	freebsd-ports@FreeBSD.org

BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython

USE_PYTHON=	yes
PLIST=		${WRKDIR}/plist
WRKSRC=		${WRKDIR}/${PORTNAME}

PYTHON_SITELIBSUBDIR=	${PYTHON_SITELIBDIR:S|^${PREFIX}/||}
MY_SITELIBDIR=		${PYTHON_SITELIBDIR}/${PORTNAME}
MY_SITELIBSUBDIR=	${PYTHON_SITELIBSUBDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

CPIO?=	/usr/bin/cpio

PYVERSION=	${PYTHON_VERSION:S/^python//}
.if defined(PYTHON_VERSION) && ${PYVERSION:S/.//} < 22
.undef		NO_IGNORE
BROKEN=		This port requires python 2.2 or later
.endif # defined(PYVERSION) && ${PYVERSION:S/.//} < 22

post-patch:
	cd ${WRKSRC}; ${RM} -f *.tar.gz; >${PLIST}

# make the plist here (for now)
do-build:
	cd ${WRKSRC};\
	echo bin/${PORTNAME} >${PLIST};\
	${FIND} . ! -type d | cut -c3- | sort \
		| ${SED} -e "s|^|${MY_SITELIBSUBDIR}/|" >>${PLIST};\
	${FIND} . -type d | cut -c3- | sort -r \
		| ${SED} -e "s|^|@dirrm ${MY_SITELIBSUBDIR}/|" >>${PLIST}

do-install:
	${MKDIR} ${MY_SITELIBDIR}
	cd ${WRKSRC};\
	${FIND} . | cut -c3- \
		| ${CPIO} -pdmv -R ${LIBOWN}:${LIBGRP} ${MY_SITELIBDIR};\
	cd ${MY_SITELIBDIR};\
	${FIND} . -type d | cut -c3- | ${XARGS} ${CHMOD} ${BINMODE};\
	${FIND} . -type f | cut -c3- | ${XARGS} ${CHMOD} ${LIBMODE};\
	${RM} -f ${PREFIX}/bin/${PORTNAME};\
	${LN} -s ${MY_SITELIBDIR}/main.py ${PREFIX}/bin/${PORTNAME}
	${CHMOD} ${BINMODE} ${MY_SITELIBDIR}/main.py

.include <bsd.port.post.mk>

#EOF
