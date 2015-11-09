# Created by: Rui Lopes <rgl ruilopes com>
# $FreeBSD$

PORTNAME=	tailor
PORTVERSION=	0.9.35
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://darcs.arstecnica.it/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Migrates changesets between version control systems

BROKEN=		unfetchable

RUN_DEPENDS=	${LOCALBASE}/bin/rsync:${PORTSDIR}/net/rsync

USES=		python
USE_PYTHON=	distutils
OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
