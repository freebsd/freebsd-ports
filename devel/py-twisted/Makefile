# New ports collection makefile for:	py-twisted
# Date created:		16 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	twisted
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	devel net python
MASTER_SITES=	http://twisted.sourceforge.net/ \
		http://twistedmatrix.com/downloads/ \
		http://twistedmatrix.com/downloads/old/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Twisted_NoDocs-${PORTVERSION}
WRKSRC=		${WRKDIR}/Twisted-${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org
COMMENT=	An event-based Python framework for internet applications

CONFLICTS=	py-twistedCore-[0-9]*

# - Note that Twisted ships with some graphical examples and clients that
#   require PyGNOME to run.  These are not central to the funcitoning of
#   Twisted, but the user should feel free to install x11-toolits/py-gnome
#   separately if desired.

USE_BZIP2=	yes
USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

PLIST_SUB+=	S=${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}

post-install:
	@ ${MKDIR} ${DATADIR}/admin
	@ ${INSTALL_SCRIPT} ${WRKSRC}/admin/accepttests \
	  ${WRKSRC}/admin/runtests ${DATADIR}/admin

.include <bsd.port.mk>
