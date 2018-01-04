# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	sgfsummary
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	http://gotools.sourceforge.net/sgfsummary/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SGF Summarizer

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/sgflib.py:games/py-sgflib@${FLAVOR}

USES=		python shebangfix tar:tgz
USE_PYTHON=	flavors
SHEBANG_FILES=	sgfsummary.py
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/sgfsummary.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sgfsummary.py ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
