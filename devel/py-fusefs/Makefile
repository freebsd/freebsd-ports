# New ports collection makefile for:	py-fusefs
# Date created:		22 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fusefs
DISTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	SF/fuse/fuse-python/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	fuse-python-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FUSE Python bindings

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
USE_GNOME=	pkgconfig
USE_ICONV=	yes
PORTDOCS=	AUTHORS Changelog FAQ INSTALL README.1st README.historic \
		README.new_fusepy_api
PORTEXAMPLES=	_find_fuse_parts.py hello.py xmp.py
PYDISTUTILS_PKGNAME=	fuse-python
PYDISTUTILS_INSTALLARGS=-Z -O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${PYEASYINSTALL_EGG}
PYEASYINSTALL_ARCHDEP=	yes
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
