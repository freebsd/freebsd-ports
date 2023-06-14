PORTNAME=	elelabs-zigbee-ezsp-utility
DISTVERSION=	20220218
CATEGORIES=	comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Elelabs Firmware Update Utility
WWW=		https://github.com/Elelabs/elelabs-zigbee-ezsp-utility

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>=3.4:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmodem>=0.4.5:comms/py-xmodem@${PY_FLAVOR}

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	Elelabs
GH_TAGNAME=	7fc415497f7e2b3410e3350b359ac5c71043399e
USE_PYTHON=	flavors

SHEBANG_FILES=	Elelabs_EzspFwUtility.py

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|data/EFR32|${DATADIR}/EFR32|g" \
		${WRKSRC}/Elelabs_EzspFwUtility.py

# This is to prevent Mk/Uses/python.mk do-configure target from firing.
do-configure:
	@${ECHO} 'No configure'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Elelabs_EzspFwUtility.py ${STAGEDIR}${PREFIX}/bin/
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/Elelabs_EzspFwUtility.py
	(cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

post-install:
# Regenerate .PLIST.pymodtemp to get all installed files from
# ${STAGEDIR}.
	@${FIND} ${STAGEDIR} -type f -o -type l | \
		${SORT} | ${SED} -e 's|${STAGEDIR}||' \
		>> ${WRKDIR}/.PLIST.mktmp

.include <bsd.port.mk>
