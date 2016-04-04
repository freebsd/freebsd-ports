# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	sgfsummary
PORTVERSION=	1.0
CATEGORIES=	games python
MASTER_SITES=	http://gotools.sourceforge.net/sgfsummary/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SGF Summarizer

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/sgflib.py:games/py-sgflib

PLIST_FILES=	bin/sgfsummary.py
USES=		python
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sgfsummary.py ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
