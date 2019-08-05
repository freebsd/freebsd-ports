# Created by: Sahil Tandon <sahil@tandon.net>
# $FreeBSD$

PORTNAME=	namebench
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	dns python benchmarks
MASTER_SITES=	SF/bsdsrc/${.CURDIR:T} \
		https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source DNS benchmark utility

LICENSE=	APACHE20

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.5.5:devel/py-Jinja2@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}graphy>=1.0:graphics/py-graphy@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}dnspython>=1.9.4:dns/py-dnspython@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}httplib2>=0.6.0:www/py-httplib2@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}simplejson>=2.1.6:devel/py-simplejson@${PY_FLAVOR}

USES=	python tar:tgz

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tkinter>=2.7.1:x11-toolkits/py-tkinter@${PY_FLAVOR}
.endif

MAKE_ENV+=	NO_THIRD_PARTY=yes
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	README.txt

USE_PYTHON=	distutils autoplist

PYDISTUTILS_INSTALLARGS+=	--install-data=${PREFIX}/share

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/libnamebench/util.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
