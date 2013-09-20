# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pychecker
PORTVERSION=	0.8.19
CATEGORIES=	devel python
MASTER_SITES=	SF

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Python source code checking tool to help hunting common bugs

USE_PYTHON=		-2.7
USE_PYDISTUTILS=	yes

DOCS=		ChangeLog COPYRIGHT KNOWN_BUGS MAINTAINERS README TODO VERSION

.if !defined(NOPORTDOCS)
NO_STAGE=	yes
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
