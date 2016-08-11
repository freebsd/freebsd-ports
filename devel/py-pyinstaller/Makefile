# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyinstaller
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyInstaller-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Program to create standalone executables from Python scripts

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

OPTIONS_DEFINE=	DOCS

EXTRACT_AFTER_ARGS=	--exclude doc/source --no-same-owner --no-same-permissions
USES=		python
USE_PYTHON=	autoplist distutils

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e '/install_requires/s,distribute,setuptools,' \
		${WRKSRC}/${PYSETUP}
	@${REINPLACE_CMD} -e '/\/sbin\/ldconfig/s,-p,-r,' \
		${WRKSRC}/PyInstaller/bindepend.py \
		${WRKSRC}/PyInstaller/depend/utils.py
	@${REINPLACE_CMD} -e '/libpython/s,\.so\.1\.0,.so.1,' \
		${WRKSRC}/PyInstaller/bindepend.py

pre-build:
	cd ${WRKSRC}/bootloader && ${PYTHON_CMD} waf configure build install

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
