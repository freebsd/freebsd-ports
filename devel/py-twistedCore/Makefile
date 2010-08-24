# New ports collection makefile for:	py-twisted
# Date created:		13 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedCore
PORTVERSION=	10.1.0
CATEGORIES=	devel net python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Core/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedCore-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	An asynchronous networking framework for Python - Core module

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zopeInterface>=3.3.0_1:${PORTSDIR}/devel/py-zopeInterface
RUN_DEPENDS=	${BUILD_DEPENDS}

# - Note that Twisted ships with some graphical examples and clients that
#   require PyGNOME to run.  These are not central to the funcitoning of
#   Twisted, but the user should feel free to install x11-toolits/py-gnome
#   separately if desired.

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Twisted_Core

MAN1=	manhole.1 mktap.1 pyhtmlizer.1 tap2deb.1 tap2rpm.1 tapconvert.1 trial.1 twistd.1

post-install:
# permission safeness
	@${CHMOD} -R ${SHAREMODE} ${PYTHONPREFIX_SITELIBDIR}/twisted/
	@${CHMOD} -R a+X ${PYTHONPREFIX_SITELIBDIR}/twisted/
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/man/${i} ${PREFIX}/man/man1/
.endfor

.include <bsd.port.mk>
