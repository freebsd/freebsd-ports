# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	ditrack
PORTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tracking system based on Subversion repository

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	svn:devel/subversion

USES=		python:2.7 shebangfix tar:tgz
SHEBANG_FILES=	upgrade-0.7-db.py
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	DITrack
WRKSRC=		${WRKDIR}/DITrack-${PORTVERSION}
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/upgrade-0.7-db.py ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/index.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
