# New ports collection makefile for:	py-fusefs
# Date created:		22 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fusefs
DISTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	SF/fuse
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	fuse-python-${DISTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	FUSE Python bindings

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GNOME=	pkgconfig
PORTDOCS=	AUTHORS Changelog FAQ INSTALL README.1st README.historic \
		README.new_fusepy_api
PORTEXAMPLES=	_find_fuse_parts.py hello.py xmp.py
PYDISTUTILS_PKGNAME=	fuse-python
PYDISTUTILS_NOEGGINFO=	yes
PLIST_SUB=	PYDISTUTILS_EGGINFO="${PYDISTUTILS_EGGINFO}"
DOCSDIR?=	${PREFIX}/share/doc/py-fusefs
EXAMPLESDIR?=	${PREFIX}/share/examples/py-fusefs

post-patch:
	@${REINPLACE_CMD} -e '/libs =/s|$$| + " -liconv"|'\
		${WRKSRC}/setup.py

post-install:
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
.ifndef NOPORTEXAMPLES
	@${INSTALL} -d ${EXAMPLESDIR}/
	@cd ${WRKSRC}/example/&&${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
