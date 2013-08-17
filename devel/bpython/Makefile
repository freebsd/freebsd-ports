# Created by: Yi-Jheng Lin <yzlin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bpython
PORTVERSION=	0.11
CATEGORIES=	devel python
MASTER_SITES=	http://bpython-interpreter.org/releases/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fancy interface to the Python interpreter

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=0:${PORTSDIR}/textproc/py-pygments

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

MAN1=		bpython.1
MAN5=		bpython-config.5

post-install:
	@${INSTALL_MAN} ${WRKSRC}/doc/bpython.1 ${MANPREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/doc/bpython-config.5 ${MANPREFIX}/man/man5

.include <bsd.port.mk>
