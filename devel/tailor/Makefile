# Created by: Rui Lopes <rgl ruilopes com>
# $FreeBSD$

PORTNAME=	tailor
PORTVERSION=	0.9.35
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://darcs.arstecnica.it/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Migrates changesets between version control systems

RUN_DEPENDS=	${LOCALBASE}/bin/rsync:${PORTSDIR}/net/rsync

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
INSTALLS_EGGINFO=	yes
OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
