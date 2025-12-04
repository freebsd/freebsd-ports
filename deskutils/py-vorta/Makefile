PORTNAME=	vorta
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	deskutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Desktop Backup Client for Borg Backup
WWW=		https://vorta.borgbase.com/

LICENSE=	APACHE20 GPLv3 OFL11
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/src/vorta/assets/icons/APACHE.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_OFL11=	${WRKSRC}/src/vorta/assets/icons/OFL.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}borgbackup>=1.2.7:archivers/py-borgbackup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}peewee>=3.15.0:databases/py-peewee@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=3.11.0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.9.8:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=3.11.10:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qt6-pyqt>=6.6.1:devel/py-qt6-pyqt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}SecretStorage>=3.3.1:security/py-SecretStorage@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	borgbase
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

PLIST_FILES=	${DESKTOPDIR:S,${PREFIX}/,,1}/${DESKTOP_FILE} \
		${ICONDIR}/${VORTAICON}

DESKTOP_FILE=	${REVDOMAIN}.desktop
ICONDIR=	share/icons/hicolor/scalable/apps
REVDOMAIN=	com.borgbase.Vorta
VORTAICON=	${REVDOMAIN}.svg

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${ICONDIR} && \
		${INSTALL_DATA} ${WRKSRC}/package/icon-symbolic.svg \
			${STAGEDIR}${PREFIX}/${ICONDIR}/${VORTAICON}
	@(cd ${STAGEDIR}${DESKTOPDIR} && \
		${RLN} ../..${PYTHONPREFIX_SITELIBDIR:S,${PREFIX},,1}/${PORTNAME}/assets/metadata/${DESKTOP_FILE} \
		${DESKTOP_FILE})

.include <bsd.port.mk>
