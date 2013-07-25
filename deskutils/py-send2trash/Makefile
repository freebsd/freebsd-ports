# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	send2trash
PORTVERSION=	1.3.0
CATEGORIES=	deskutils
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Send2Trash-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Small package that sends files to the Trash

LICENSE=	BSD

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_PKGNAME=	Send2Trash

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

PORTDOCS=	CHANGES.rst README.rst

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
