# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedCore
PORTVERSION=	13.2.0
CATEGORIES=	devel net python
MASTER_SITES=	http://twistedmatrix.com/Releases/Core/${PORTVERSION:R}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedCore-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Asynchronous networking framework for Python - Core module

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=3.6.0:${PORTSDIR}/devel/py-zope.interface
RUN_DEPENDS:=	${BUILD_DEPENDS}

# - Note that Twisted ships with some graphical examples and clients that
#   require PyGNOME to run.  These are not central to the funcitoning of
#   Twisted, but the user should feel free to install x11-toolits/py-gnome
#   separately if desired.

NO_STAGE=	yes
USE_BZIP2=	yes
USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	${PORTNAME:S/twisted/Twisted_/}
REINPLACE_ARGS=	-i ''

MAN1=		manhole.1 pyhtmlizer.1 tap2deb.1 tap2rpm.1 tapconvert.1 trial.1 twistd.1

post-install:
# permission safeness
	@${CHMOD} -R ${SHAREMODE} ${PYTHONPREFIX_SITELIBDIR}/twisted/
	@${CHMOD} -R a+X ${PYTHONPREFIX_SITELIBDIR}/twisted/
	cd ${WRKSRC}/doc/man/ && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
