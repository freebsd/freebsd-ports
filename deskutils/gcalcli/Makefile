# Created by: ijliao
# $FreeBSD$

PORTNAME=	gcalcli
PORTVERSION=	3.2
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	ports@thelanman.net
COMMENT=	Google Calendar Command Line Interface

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil \
		${PYTHON_SITELIBDIR}/gdata/__init__.py:devel/py-gdata \
		${PYTHON_SITELIBDIR}/gflags.py:devel/py-gflags \
		${PYTHON_SITELIBDIR}/apiclient/__init__.py:www/py-google-api-python-client \
		${PYTHON_SITELIBDIR}/httplib2/__init__.py:www/py-httplib2

USE_GITHUB=	yes
GH_ACCOUNT=	insanum

USES=		python

NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	README.md gcalcli_?.png

PLIST_FILES=	bin/gcalcli

OPTIONS_DEFINE=		DOCS FUZZYDATES ICS_VCAL SIMPLEJSON
OPTIONS_DEFAULT=	ICS_VCAL

ICS_VCAL_DESC=		enable importing of ics/vcal files
SIMPLEJSON_DESC=	use simplejson for url shortening
FUZZYDATES_DESC=	use parsedatetime for fuzzy date parsing

ICS_VCAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vobject>=0.4.8:deskutils/py-vobject
SIMPLEJSON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=0:devel/py-simplejson
FUZZYDATES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}parsedatetime>=0:devel/py-parsedatetime

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
