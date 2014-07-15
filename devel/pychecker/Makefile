# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pychecker
PORTVERSION=	0.8.19
CATEGORIES=	devel python
MASTER_SITES=	SF

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Python source code checking tool to help hunting common bugs

LICENSE=	BSD3CLAUSE

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

DOCS=		ChangeLog COPYRIGHT KNOWN_BUGS MAINTAINERS README TODO VERSION

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
