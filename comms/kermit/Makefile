PORTNAME=	kermit
DISTVERSIONPREFIX=	v
DISTVERSION=	11.0.511
CATEGORIES=	comms ftp net

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Portable scriptable network and serial communication program
WWW=		https://www.openkermit.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.TXT

TEST_DEPENDS=	check>=0:devel/check \
		pkgconf>=1.3.0_1:devel/pkgconf \
		${PYTHON_PKGNAMEPREFIX}pyftpdlib>=0:ftp/py-pyftpdlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		pytest ssl
USE_GITHUB=	yes
GH_ACCOUNT=	OpenKermit
GH_PROJECT=	ckermit

MAKEFILE=	makefile
ALL_TARGET=	freebsd+ssl
MAKE_ARGS=	CC="${CC}" CC2="${CC}" \
		SSLINC="-I${OPENSSLINC}" SSLLIB="-L${OPENSSLLIB}"
PYTEST_ARGS=	-n ${MAKE_JOBS_NUMBER}

PLIST_FILES=	bin/kermit share/man/man1/kermit.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's^-O2 -pipe^${CFLAGS}^' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wermit ${STAGEDIR}${PREFIX}/bin/kermit
	${INSTALL_MAN} ${WRKSRC}/ckuker.nr \
		${STAGEDIR}${PREFIX}/share/man/man1/kermit.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${STAGEDIR}${DOCSDIR}

pre-test:
	@cd ${TEST_WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${TEST_ARGS} check

.include <bsd.port.mk>
