# Created by: rene@FreeBSD.org (repocopied from audio/py-mpd)
# $FreeBSD$

PORTNAME=	mpd2
PORTVERSION=	0.5.5
DISTVERSIONPREFIX=	v
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fork of the Python MPD client library

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	Mic92
GH_PROJECT=	python-${PORTNAME}

USES=		shebangfix python
SHEBANG_FILES=	examples/helloworld.py
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/topics
	${INSTALL_DATA} ${WRKSRC}/doc/commands_header.txt ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.rst ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/topics/*.rst ${STAGEDIR}${DOCSDIR}/topics/
	${INSTALL_SCRIPT} ${WRKSRC}/doc/generate_command_reference.py ${STAGEDIR}${DOCSDIR}/

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.py ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/summary.txt ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
