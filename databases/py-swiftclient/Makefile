# Created by: Mikolaj Golub <trociny@FreeBSD.org>
# $FreeBSD$

PORTNAME=	swiftclient
PORTVERSION=	1.5.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Python client library for OpenStack Object Storage (Swift)

LICENSE=	AL2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=0.5.19:${PORTSDIR}/devel/py-pbr

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.0.9:${PORTSDIR}/devel/py-simplejson

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	python_${PORTNAME}

PLIST_FILES=	bin/swift \
		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

MAN1=		swift.1

post-patch:
	@${REINPLACE_CMD} -e "s/'d2to1', //; s/d2to1=True/pbr=True/" \
		${WRKSRC}/setup.py

post-install:
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/manpages/${i} ${MANPREFIX}/man/man1/${i}
.endfor

.include <bsd.port.mk>
