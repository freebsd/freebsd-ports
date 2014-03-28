# Created by: ijliao
# $FreeBSD$

PORTNAME=	gcalcli
PORTVERSION=	2.4.2
CATEGORIES=	deskutils

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Google Calendar Command Line Interface

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gdata/__init__.py:${PORTSDIR}/devel/py-gdata \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil

USE_GITHUB=	yes
GH_ACCOUNT=	insanum
GH_PROJECT=	gcalcli
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	a0fc61a

USE_PYTHON=	yes

NO_BUILD=	yes

PORTDOCS=	README.md gcalcli_?.png

PLIST_FILES=	bin/gcalcli

OPTIONS_DEFINE=		DOCS FUZZYDATES ICS_VCAL SIMPLEJSON
OPTIONS_DEFAULT=	ICS_VCAL

ICS_VCAL_DESC=		enable importing of ics/vcal files
SIMPLEJSON_DESC=	use simplejson for url shortening
FUZZYDATES_DESC=	use parsedatetime for fuzzy date parsing

ICS_VCAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vobject>=0.4.8:${PORTSDIR}/deskutils/py-vobject
SIMPLEJSON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=0:${PORTSDIR}/devel/py-simplejson
FUZZYDATES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}parsedatetime>=0:${PORTSDIR}/devel/py-parsedatetime

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
