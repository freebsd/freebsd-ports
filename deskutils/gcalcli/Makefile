# Created by: ijliao
# $FreeBSD$

PORTNAME=	gcalcli
PORTVERSION=	3.2
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	deskutils python

MAINTAINER=	ports@thelanman.net
COMMENT=	Google Calendar Command Line Interface

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gdata>=0:devel/py-gdata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-api-python-client>=0:www/py-google-api-python-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gflags>=0:devel/py-python-gflags@${PY_FLAVOR}

USES=		python:-2.7 shebangfix
USE_GITHUB=	yes
SHEBANG_FILES=	gcalcli

GH_ACCOUNT=	insanum

OPTIONS_DEFINE=		DOCS FUZZYDATES ICS_VCAL SIMPLEJSON
OPTIONS_DEFAULT=	ICS_VCAL

ICS_VCAL_DESC=		Enable importing of ics/vcal files
SIMPLEJSON_DESC=	Use simplejson for url shortening
FUZZYDATES_DESC=	Use parsedatetime for fuzzy date parsing

ICS_VCAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vobject>=0.4.8:deskutils/py-vobject@${PY_FLAVOR}
SIMPLEJSON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=0:devel/py-simplejson@${PY_FLAVOR}
FUZZYDATES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}parsedatetime>=0:devel/py-parsedatetime@${PY_FLAVOR}

NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	README.md gcalcli_?.png
PLIST_FILES=	bin/gcalcli

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
