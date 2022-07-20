PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION} # to keep in sync with thrift
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	APACHE/thrift/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	komarov@valerka.net
COMMENT=	Python interface to Thrift

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../LICENSE

DISTINFO_FILE=	${PORTSDIR}/devel/thrift/distinfo

USES=		cpe python:3.6+
CPE_VENDOR=	apache
USE_PYTHON=	distutils autoplist

WRKSRC=		${WRKDIR}/${DISTNAME}/lib/py

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools|do_not_use_&|' ${WRKSRC}/${PYSETUP}

.include "../thrift/bsd.thrift.mk"
.include <bsd.port.mk>
