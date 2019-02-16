# $FreeBSD$

PORTNAME=	remotery
DISTVERSION=	g20190209
CATEGORIES=	devel

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Single file, realtime CPU/GPU profiler library with remote web viewer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Celtoys
GH_PROJECT=	Remotery
GH_TAGNAME=	38f3ed9

PORTDOCS=	readme.md
PORTEXAMPLES=	sample sample.c
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES

# We use an empty do-build target here instead of setting NO_BUILD because
# otherwise post-build-EXAMPLES-on would never run.
do-build:

post-build-EXAMPLES-on:
	cd ${WRKSRC} && ${CC} -I./lib -pthread -lm -o ./sample/sample \
		./lib/Remotery.c ./sample/sample.c

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} vis ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/Remotery.c ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/Remotery.h ${STAGEDIR}${PREFIX}/include

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/sample.c ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/sample/sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
