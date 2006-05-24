# New ports collection makefile for: trac
# Date created:                      17 April 2004
# Whom:                              Kuei-Feng Li <thinker@branda.to>
#
# $FreeBSD$
#

PORTNAME=	trac
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	japanese www devel python
MASTER_SITES=	http://dist.bsdlab.org/ \
		http://www.i-act.co.jp/project/products/downloads/
DISTFILES=	${PORTNAME}-${PORTVERSION}-ja-1.zip

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	An enhanced wiki and issue tracking system for software projects

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite20 \
		${PYTHON_SITELIBDIR}/neo_cgi.so:${PORTSDIR}/www/clearsilver-python \
		${PYTHON_SITELIBDIR}/svn/__init__.py:${PORTSDIR}/devel/subversion-python \
		${PYTHON_SITELIBDIR}/japanese.pth:${PORTSDIR}/japanese/pycodec
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	SILVERCITY "Use Silvercity for syntax highlighting" On \
		DOCUTILS   "Allow additional text markup" On
CONFLICTS=	trac-0.*
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-ja-1

USE_ZIP=	yes
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
		;s,share/trac,%%DATADIR%%,g \
		;s,@dirrm (%%PYTHON_SITELIBDIR%%|${PYTHON_LIBDIR:S,${PYTHONBASE}/,,})$$,,g \
		' | ${TR} -s '\n') > temp-pkg-plist

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' | ${XARGS} ${RM}

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.pre.mk>

.if defined(WITH_SILVERCITY)
RUN_DEPENDS+=	${PREFIX}/bin/source2html.py:${PORTSDIR}/textproc/silvercity
.endif

.if defined(WITH_DOCUTILS)
RUN_DEPENDS+=	${PREFIX}/bin/rst2html:${PORTSDIR}/textproc/py-docutils
.endif

.include <bsd.port.post.mk>
