# Created by: Kuei-Feng Li <thinker@branda.to>
# $FreeBSD$

PORTNAME=	trac
PORTVERSION=	0.12.3
CATEGORIES=	japanese www devel python
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.i-act.co.jp/project/products/downloads/
MASTER_SITE_SUBDIR=	kuriyama
DISTNAME=	Trac-${PORTVERSION}.ja2

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Enhanced wiki and issue tracking system for software projects

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.5:${PORTSDIR}/textproc/py-genshi \
		${PYTHON_PKGNAMEPREFIX}Babel>=0.9:${PORTSDIR}/devel/py-babel
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.5:${PORTSDIR}/textproc/py-genshi \
		${PYTHON_PKGNAMEPREFIX}Babel>=0.9:${PORTSDIR}/devel/py-babel

OPTIONS_DEFINE=	SILVERCITY DOCUTILS PYGMENTS TZ PGSQL SVN
SILVERCITY_DESC=	Use Silvercity for syntax highlighting
DOCUTILS_DESC=	Allow additional text markup
PYGMENTS_DESC=	Use generic syntax highlighter
TZ_DESC=	Process Time Zones
SVN_DESC=	Support for subversion RCS

OPTIONS_DEFAULT=	SILVERCITY DOCUTILS PYGMENTS TZ SVN

BROKEN=		fails to build

CONFLICTS=	trac-0.*

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Trac
PYDISTUTILS_NOEGGINFO=	yes
PYDISTUTILS_PKGVERSION=	${PORTVERSION}.ja2

# This target is only meant to be used by the port maintainer.
NO_STAGE=	yes
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSILVERCITY}
RUN_DEPENDS+=	${LOCALBASE}/bin/source2html.py:${PORTSDIR}/textproc/silvercity
.endif

.if ${PORT_OPTIONS:MDOCUTILS}
RUN_DEPENDS+=	${LOCALBASE}/bin/rst2html:${PORTSDIR}/textproc/py-docutils
.endif

.if ${PORT_OPTIONS:MPYGMENTS}
RUN_DEPENDS+=	${LOCALBASE}/bin/pygmentize:${PORTSDIR}/textproc/py-pygments
.endif

.if ${PORT_OPTIONS:MTZ}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopg2/__init__.py:${PORTSDIR}/databases/py-psycopg2
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
.endif

.if ${PORT_OPTIONS:MSVN}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/svn/__init__.py:${PORTSDIR}/devel/py-subversion
.endif

.include <bsd.port.mk>
