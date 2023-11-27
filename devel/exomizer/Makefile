PORTNAME=	exomizer
DISTVERSION=	3.1.2
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/magli143/exomizer/wiki/downloads/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Cruncher for 6502-based systems
WWW=		https://bitbucket.org/magli143/exomizer/wiki/Home

LICENSE=	ZLIB

USES=		gmake zip

MAKE_ARGS=	LDFLAGS="${LDFLAGS} -s" \
		SHELL="${SH} -x" \
		WFLAGS="${CFLAGS}"
ALL_TARGET=	build

NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/src

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/exomizer \
		${STAGEDIR}${PREFIX}/bin/exomizer
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/exobasic \
		${STAGEDIR}${PREFIX}/bin/exobasic
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "exodecrs rawdecrs" \
		${STAGEDIR}${DATADIR})

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
