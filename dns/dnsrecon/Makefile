PORTNAME=	dnsrecon
DISTVERSION=	0.10.1
CATEGORIES=	dns

MAINTAINER=	rihaz.jerrin@gmail.com
COMMENT=	DNS enumeration tool

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython2>=0:dns/py-dnspython2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	darkoperator

USES=		python shebangfix
NO_BUILD=	yes
NO_ARCH=	yes

SHEBANG_FILES=	${WRKSRC}/dnsrecon.py
FILELIST=	namelist.txt subdomains-top1mil-20000.txt \
		subdomains-top1mil-5000.txt subdomains-top1mil.txt

post-patch:
	@${REINPLACE_CMD} -e 's|from lib|from dnsrecon|g' ${WRKSRC}/${PORTNAME}.py \
							${WRKSRC}/lib/crtenum.py \
							${WRKSRC}/lib/yandexenum.py

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/dnsrecon
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/dnsrecon)
	${INSTALL_SCRIPT} ${WRKSRC}/dnsrecon.py ${STAGEDIR}${PREFIX}/bin/dnsrecon
	${INSTALL_DATA}	${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${FILELIST:S|^|${WRKSRC}/|} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
