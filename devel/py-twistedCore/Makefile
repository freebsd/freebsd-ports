# New ports collection makefile for:	py-twisted
# Date created:		13 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedCore
PORTVERSION=	2.5.0
PORTREVISION=	2
CATEGORIES=	devel net python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Twisted/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedCore-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	An asynchronous networking framework for Python - Core module

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zopeInterface>=3.3.0_1:${PORTSDIR}/devel/py-zopeInterface
RUN_DEPENDS=	${BUILD_DEPENDS}

CONFLICTS=	py??-twisted-[0-9]*

# - Note that Twisted ships with some graphical examples and clients that
#   require PyGNOME to run.  These are not central to the funcitoning of
#   Twisted, but the user should feel free to install x11-toolits/py-gnome
#   separately if desired.

USE_BZIP2=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

MAN1=	manhole.1 mktap.1 pyhtmlizer.1 tap2deb.1 tap2rpm.1 tapconvert.1 trial.1 twistd.1

post-install:
# permission safeness
	@${CHMOD} -R ${SHAREMODE} ${PYTHONPREFIX_SITELIBDIR}/twisted/
	@${CHMOD} -R a+X ${PYTHONPREFIX_SITELIBDIR}/twisted/
	${INSTALL_MAN} ${WRKSRC}/doc/man/manhole.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/mktap.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/pyhtmlizer.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/tap2deb.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/tap2rpm.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/tapconvert.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/trial.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/twistd.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
