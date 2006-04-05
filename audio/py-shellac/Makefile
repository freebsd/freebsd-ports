# New ports collection makefile for:	py-shellac
# Date created:				04 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	shellac
PORTVERSION=	20051017
CATEGORIES=	audio python
MASTER_SITES=	http://hem.bredband.net/b298027/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	alex@foxybanana.com
COMMENT=	Shellac is a PyGTK XMMS2 Client

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xmmsclient.so:${PORTSDIR}/audio/py-xmms2

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GNOME=	pygtk2

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in COPYING README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
