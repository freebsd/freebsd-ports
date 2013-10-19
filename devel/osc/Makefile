# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osc
PORTVERSION=	0.140.0
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Command Line Interface to work with an openSUSE Build Service

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	openSUSE
GH_COMMIT=	87df33f

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}m2crypto>0:${PORTSDIR}/security/py-m2crypto

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGVERSION=${PORTVERSION:C/^([0-9]+\.[0-9]+)\.[0-9]+/\1/}

PORTDOCS=	*

OPTIONS_DEFINE=	CA_BUNDLE DOCS
OPTIONS_DEFAULT=CA_BUNDLE
CA_BUNDLE_DESC=	Install CA Certificates

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCA_BUNDLE}
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
CA_PATH=	${LOCALBASE}/share/certs/ca-root-nss.crt
.else
CA_PATH=	/etc/ssl
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|'share', 'man'|'man'|" ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "/cert.pem/ s|\[.*\]|['${CA_PATH}']|" \
		${WRKSRC}/osc/conf.py

post-install:
	${LN} -s osc-wrapper.py ${STAGEDIR}${PREFIX}/bin/osc
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS README NEWS TODO \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
