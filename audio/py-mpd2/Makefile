# Created by: rene@FreeBSD.org (repocopied from audio/py-mpd)
# $FreeBSD$

PORTNAME=	mpd2
PORTVERSION=	0.5.4
DISTVERSIONPREFIX=	v
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Fork of the Python MPD client library

LICENSE=	LGPL3

USE_GITHUB=	yes
GH_ACCOUNT=	Mic92
GH_PROJECT=	python-${PORTNAME}

USES=		shebangfix python
SHEBANG_FILES=	examples/helloworld.py
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS_1=	commands_header.txt index.rst changes.rst
PORTDOCS_2=	topics/advanced.rst topics/commands.rst \
		topics/getting-started.rst topics/logging.rst
PORTDOCS_3=	generate_command_reference.py
PORTDOCS=	${PORTDOCS_1} ${PORTDOCS_2} ${PORTDOCS_3}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTEXAMPLES_1=	errorhandling.py helloworld.py idle.py locking.py logger.py \
		multitags.py randomqueue.py stats.py stickers.py
PORTEXAMPLES_2=	summary.txt
PORTEXAMPLES=	${PORTEXAMPLES_1} ${PORTEXAMPLES_2}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/topics
.for f in ${PORTDOCS_1}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.for f in ${PORTDOCS_2}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}/topics
.endfor
.for f in ${PORTDOCS_3}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES_1}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.for f in ${PORTEXAMPLES_2}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
