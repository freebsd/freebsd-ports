# Created by: Mikolaj Golub <trociny@FreeBSD.org>
# $FreeBSD$

PORTNAME=	swiftclient
PORTVERSION=	1.4.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Python client library for OpenStack Object Storage (Swift)

LICENSE=	AL2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>0:${PORTSDIR}/devel/py-simplejson

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	python_${PORTNAME}

PLIST_FILES=	bin/swift \
		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

MAN1=		swift.1

post-install:
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/manpages/${i} ${MANPREFIX}/man/man1/${i}
.endfor

.include <bsd.port.mk>
