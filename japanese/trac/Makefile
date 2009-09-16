# New ports collection makefile for: trac
# Date created:                      17 April 2004
# Whom:                              Kuei-Feng Li <thinker@branda.to>
#
# $FreeBSD$
#

PORTNAME=	trac
PORTVERSION=	0.11.5
CATEGORIES=	japanese www devel python
MASTER_SITES=	http://dist.bsdlab.org/ \
		http://www.i-act.co.jp/project/products/downloads/
DISTNAME=	Trac-${PORTVERSION}.ja1

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	An enhanced wiki and issue tracking system for software projects

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.5:${PORTSDIR}/textproc/py-genshi
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	SILVERCITY "Use Silvercity for syntax highlighting" On \
		DOCUTILS   "Allow additional text markup" On \
		PYGMENTS   "Use generic syntax highlighter" On \
		TZ         "Process Time Zones" On \
		PGSQL	   "Use PostgreSQL instead of SQLite3" Off \
		SUBVERSION "Support for subversion RCS" On
CONFLICTS=	trac-0.*

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Trac
PYDISTUTILS_NOEGGINFO=	yes
PYDISTUTILS_PKGVERSION=	${PORTVERSION}.ja1

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		;s,@dirrm share/man(/.*)?$$,,g \
		;s,${PYTHON_SITELIBDIR:S,^${PYTHONBASE}/,,},%%PYTHON_SITELIBDIR%%,g \
		;s,share/trac,%%DATADIR%%,g \
		;s,share/examples/trac,%%EXAMPLESDIR%%,g \
		;s,@dirrm (%%PYTHON_SITELIBDIR%%|${PYTHON_LIBDIR:S,${PYTHONBASE}/,,})$$,,g \
		' | ${TR} -s '\n') > temp-pkg-plist

pre-install:
	@${REINPLACE_CMD} -i '' -e 's|/usr/bin/python|${PYTHON_CMD}|' ${WRKSRC}/cgi-bin/trac.fcgi \
	    ${WRKSRC}/cgi-bin/trac.cgi

post-install:
	@${MKDIR} ${EXAMPLESDIR}
. for d in rpm workflow
	@${MKDIR} ${EXAMPLESDIR}/${d}
	@${INSTALL_DATA} ${WRKSRC}/contrib/${d}/* ${EXAMPLESDIR}/${d}/
	@${RM} -rf ${WRKSRC}/contrib/${d}
. endfor
	@${INSTALL_DATA} ${WRKSRC}/contrib/* ${EXAMPLESDIR}
	@${MKDIR} ${DATADIR}/cgi-bin
	@${INSTALL_SCRIPT} ${WRKSRC}/cgi-bin/* ${DATADIR}/cgi-bin
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.pre.mk>

.if defined(WITH_SILVERCITY)
RUN_DEPENDS+=	${LOCALBASE}/bin/source2html.py:${PORTSDIR}/textproc/silvercity
.endif

.if defined(WITH_DOCUTILS)
RUN_DEPENDS+=	${LOCALBASE}/bin/rst2html:${PORTSDIR}/textproc/py-docutils
.endif

.if defined(WITH_PYGMENTS)
RUN_DEPENDS+=	${LOCALBASE}/bin/pygmentize:${PORTSDIR}/textproc/py-pygments
.endif

.if defined(WITH_TZ)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopg2/__init__.py:${PORTSDIR}/databases/py-psycopg2
.else
. if ${PYTHON_REL} < 250
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite23
. else
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
. endif
.endif

.if !defined(WITHOUT_SUBVERSION)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/svn/__init__.py:${PORTSDIR}/devel/py-subversion
.endif

.include <bsd.port.post.mk>
