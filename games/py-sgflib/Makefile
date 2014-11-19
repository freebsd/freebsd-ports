# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	sgflib
PORTVERSION=	1.0
CATEGORIES=	games python
MASTER_SITES=	http://gotools.sourceforge.net/sgflib/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Smart Game Format parser library for Python

USES=		python
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} sgflib.py typelib.py \
		${STAGEDIR}${PYTHON_SITELIBDIR})

.include <bsd.port.mk>
