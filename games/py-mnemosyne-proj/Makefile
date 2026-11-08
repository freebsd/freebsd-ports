PORTNAME=	mnemosyne-proj
DISTVERSION=	2.11.1
PORTEPOCH=	1
CATEGORIES=	games education python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mnemosyne_proj-${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Flash-card tool which optimises your learning process
WWW=		https://www.mnemosyne-proj.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR} \
		gmake>0:devel/gmake
RUN_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}argon2-cffi>0:security/py-argon2-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cheroot>=5.0:www/py-cheroot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cherrypy>=18.8.0:www/py-cherrypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=5.1.1:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gTTS>=0:audio/py-gtts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=2.1.0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=7.4.0,1:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=7.0.1,1:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.4:www/py-webob@${PY_FLAVOR}
TEST_DEPENDS=	dvipng:print/texlive-base \
		latex:print/tex-formats

USES=		pyqt:6 python qt:6 shebangfix
USE_PYQT=	pyqt6:run webengine:run
USE_PYTHON=	autoplist concurrent pep517 pytest
PYTEST_IGNORED_TESTS=	TestCardType TestDBImport TestGuiTranslator TestLogging \
			TestMemImport test_install_plugin test_machine_id \
			test_add_tag test_edit_tag test_delete_tag \
			test_add_fact test_edit_fact test_delete_fact \
			test_add_cards test_edit_cards test_rename_tag \
			test_delete_cards test_repetition test_add_media \
			test_edit_media test_unicode_database_name \
			test_dont_upload_science_logs \
			test_do_upload_science_logs test_add_card_type \
			test_edit_card_type test_convert_chain test_mem_import
USE_QT=		sqldriver-sqlite:run

SHEBANG_FILES=	mnemosyne/pyqt_ui/mnemosyne

BINARY_ALIAS=	make=gmake

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 31300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}legacy-cgi>0:www/py-legacy-cgi@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
