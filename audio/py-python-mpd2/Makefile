# Created by: rene@FreeBSD.org (repocopied from audio/py-mpd)
# $FreeBSD$

PORTNAME=	python-mpd2
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python MPD client library

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Mic92

SHEBANG_FILES=	doc/*.py examples/*.py

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/topics
	${INSTALL_DATA} ${WRKSRC}/doc/commands_header.txt ${WRKSRC}/doc/*.rst ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/topics/*.rst ${STAGEDIR}${DOCSDIR}/topics/
	${INSTALL_SCRIPT} ${WRKSRC}/doc/generate_command_reference.py ${STAGEDIR}${DOCSDIR}/

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.py ${WRKSRC}/examples/summary.txt ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
