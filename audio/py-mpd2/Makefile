# Created by: rene@FreeBSD.org (repocopied from audio/py-mpd)
# $FreeBSD$

PORTNAME=	mpd2
PORTVERSION=	0.5.2
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Fork of the Python MPD client library

USE_GITHUB=	yes
NO_STAGE=	yes
GH_ACCOUNT=	Mic92
GH_PROJECT=	python-${PORTNAME}
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	df508d4

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	python_mpd2

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	DOCS EXAMPLES

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS_1=	index.rst changes.rst
PORTDOCS_2=	topics/advanced.rst topics/commands.rst \
		topics/getting-started.rst topics/logging.rst
PORTDOCS=	${PORTDOCS_1} ${PORTDOCS_2}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTEXAMPLES=	locking.py logger.py

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/topics
.for f in ${PORTDOCS_1}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.for f in ${PORTDOCS_2}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}/topics
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
