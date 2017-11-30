# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	sgflib
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	http://gotools.sourceforge.net/sgflib/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Smart Game Format parser library for Python

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/lgpl.txt

USES=		python shebangfix
USE_PYTHON=	flavors
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

do-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/bin/python|${python_CMD}|' \
		${WRKSRC}/*.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} sgflib.py typelib.py \
		${STAGEDIR}${PYTHON_SITELIBDIR})

.include <bsd.port.mk>
