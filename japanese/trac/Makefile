# New ports collection makefile for: trac
# Date created:                      17 April 2004
# Whom:                              Kuei-Feng Li <thinker@branda.to>
#
# $FreeBSD$
#

PORTNAME=	trac
PORTVERSION=	0.8.1
CATEGORIES=	www devel python
MASTER_SITES=	http://ftp.edgewall.com/pub/trac/ \
		ftp://ftp.edgewall.com/pub/trac/

MAINTAINER=	thinker@branda.to
COMMENT=	An enhanced wiki and issue tracking system for software projects

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/sqlite/main.py:${PORTSDIR}/databases/py-PySQLite10 \
		${PYTHON_SITELIBDIR}/neo_cgi.so:${PORTSDIR}/www/clearsilver-python \
		${PYTHON_SITELIBDIR}/svn/__init__.py:${PORTSDIR}/devel/subversion-python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MAN1=		trac-admin.1 tracd.1 tracdb2env.1

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		;s,@dirrm share/man(/.*)?$$,,g \
		;s,${PYTHON_SITELIBDIR:S,^${PYTHONBASE}/,,},%%PYTHON_SITELIBDIR%%,g \
		;s,@dirrm (%%PYTHON_SITELIBDIR%%|${PYTHON_LIBDIR:S,${PYTHONBASE}/,,})$$,,g \
		' | ${TR} -s '\n') > temp-pkg-plist

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
