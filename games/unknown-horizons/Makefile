# Created by: GreenDog <fiziologus@gmail.com>
# $FreeBSD$

PORTNAME=	unknown-horizons
PORTVERSION=	2013.3
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	fiziologus@gmail.com
COMMENT=	Real time simulation game

BROKEN=		unfetchable

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
		${LOCALBASE}/bin/xsltproc:textproc/libxslt
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/fife/__init__.py:games/py-fife@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/yaml/__init__.py:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gdbm>0:databases/py-gdbm@${PY_FLAVOR}

ONLY_FOR_ARCHS=	i386 amd64

USES=		gettext-tools python:2.7 shebangfix tar:xz
USE_GITHUB=	yes
USE_GNOME=	intltool
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	UnknownHorizons
SHEBANG_FILES=	run_uh.py

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
ENET_DIR=	x86
PLIST_SUB+=	X86_ONLY=""
.else
PLIST_SUB+=	X86_ONLY="@comment "
.endif

.if ${ARCH} == amd64
ENET_DIR=	x64
PLIST_SUB+=	X64_ONLY=""
.else
PLIST_SUB+=	X64_ONLY="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|http://docbook.sourceforge.net/release/xsl/current|${LOCALBASE}/share/xsl/docbook|" \
		-e "s|share/man/man6|man/man6|" ${WRKSRC}/setup.py

# Install multiplayer lib (enet+pyenet)
post-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/horizons/network/libs/freebsd-${ENET_DIR}
	${INSTALL_LIB} ${WRKSRC}/horizons/network/libs/freebsd-${ENET_DIR}/enet.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/horizons/network/libs/freebsd-${ENET_DIR}/enet.so
# (rene) prune unwanted files to pass 'make check-plist'
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/UnknownHorizons-_unknown_-py${PYTHON_VER}.egg-info

.include <bsd.port.post.mk>
