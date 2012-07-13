# New ports collection makefile for:	py-twisted
# Date created:				13 April 2005
# Whom:					Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedCore
PORTVERSION=	12.1.0
PORTREVISION=	1
CATEGORIES=	devel net python
MASTER_SITES=	http://twistedmatrix.com/Releases/Core/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedCore-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	An asynchronous networking framework for Python - Core module

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=3.3.0:${PORTSDIR}/devel/py-zope.interface

# - Note that Twisted ships with some graphical examples and clients that
#   require PyGNOME to run.  These are not central to the funcitoning of
#   Twisted, but the user should feel free to install x11-toolits/py-gnome
#   separately if desired.

USE_BZIP2=	yes
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME:S/twisted/Twisted_/}
REINPLACE_ARGS=	-i ''

MAN1=		manhole.1 pyhtmlizer.1 tap2deb.1 tap2rpm.1 tapconvert.1 trial.1 twistd.1

post-patch:
	@${REINPLACE_CMD} -e '/preventImports=/ s|"gi"|""|' ${WRKSRC}/twisted/internet/gtk2reactor.py

post-install:
# permission safeness
	@${CHMOD} -R ${SHAREMODE} ${PYTHONPREFIX_SITELIBDIR}/twisted/
	@${CHMOD} -R a+X ${PYTHONPREFIX_SITELIBDIR}/twisted/
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/man/${i} ${MANPREFIX}/man/man1/
.endfor

.include <bsd.port.mk>
