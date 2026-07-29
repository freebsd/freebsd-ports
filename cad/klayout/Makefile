PORTNAME=	klayout
DISTVERSION=	0.30.10
CATEGORIES=	cad
MASTER_SITES=	https://www.klayout.org/downloads/source/

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Qt-based chip mask layout viewing and editing tool
WWW=		https://www.klayout.de/

LICENSE=	GPLv2

BROKEN_i386=	type 'hash<long long>' does not provide a call operator
BROKEN_powerpc=	type 'hash<long long>' does not provide a call operator

BUILD_DEPENDS=	bash:shells/bash

USES=		compiler:c++0x gmake gl python ruby qt:6 shebangfix tar:bz2
USE_GL=		opengl
USE_QT=		5compat base multimedia svg tools
SHEBANG_FILES=	build.sh

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	build.sh
CONFIGURE_ARGS=		-qmake qmake6 \
			-with-qtbinding \
			-prefix '${PREFIX}/${PORTNAME}' \
			-python ${PYTHON_CMD} \
			-ruby ${RUBY} \
			-nolibgit2 \
			-dry-run
# need both due to project quirk
MAKE_ARGS=		INSTALL_ROOT=${STAGEDIR} \
			INSTALLROOT=${STAGEDIR}

EXTRACT_AFTER_ARGS=	--exclude .git* \
			--exclude Jenkinsfile* \
			--exclude *mac.py \
			--exclude macbuild \
			--exclude ci-scripts \
			--exclude dropbox-deployment.yml \
			--exclude scripts \
			--exclude src/gsiqt/qt4 \
			--exclude src/gsiqt/qt5 \
			--exclude travis-build.sh \
			--no-same-owner --no-same-permissions

BUILD_WRKSRC=	${WRKSRC}/build-release
INSTALL_WRKSRC=	${WRKSRC}/build-release
PLIST_SUB=	DISTVERSION=${DISTVERSION} DISTVERSION_R=${DISTVERSION:R}

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/${PORTNAME}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${PORTNAME}/pymod/${PORTNAME}/*${PYTHON_TAG}.so

.include <bsd.port.mk>
