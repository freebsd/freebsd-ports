# Created by: Rui Lopes <rgl ruilopes com>
# $FreeBSD$

PORTNAME=	tailor
PORTVERSION=	0.9.35
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	https://BSDforge.com/projects/source/devel/tailor/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Migrates changesets between version control systems

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	${LOCALBASE}/bin/rsync:net/rsync

USES=		python:2.7
USE_PYTHON=	distutils
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
