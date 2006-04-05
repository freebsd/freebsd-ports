# New ports collection makefile for:	py-twisted
# Date created:		13 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedCore
PORTVERSION=	2.2.0
CATEGORIES=	devel net python
MASTER_SITES=	http://twistedmatrix.com/downloads/Twisted/${PORTVERSION:R}/ \
		http://tmrc.mit.edu/mirror/twisted/Twisted/${PORTVERSION:R}/
#MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Twisted-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	An asynchronous networking framework for Python - Core module

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/zope/interface:${PORTSDIR}/devel/py-zopeInterface
RUN_DEPENDS=	${BUILD_DEPENDS}

CONFLICTS=	py??-twisted-[0-9]*

WRKSRC=		${WRKDIR}/Twisted-${PORTVERSION}

# - Note that Twisted ships with some graphical examples and clients that
#   require PyGNOME to run.  These are not central to the funcitoning of
#   Twisted, but the user should feel free to install x11-toolits/py-gnome
#   separately if desired.

USE_BZIP2=	yes
USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

PLIST_SUB+=	S=${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}

post-install:
# permission safeness
	@${CHMOD} -R ${SHAREMODE} ${PYTHONPREFIX_SITELIBDIR}/twisted/
	@${CHMOD} -R a+X ${PYTHONPREFIX_SITELIBDIR}/twisted/

.include <bsd.port.mk>
