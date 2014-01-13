# Created by: GreenDog <fiziologus@gmail.com>
# $FreeBSD$

PORTNAME=		unknown-horizons
PORTVERSION=		2013.2
CATEGORIES=		games
MASTER_SITES=		SF/unknownhorizons/Unknown%20Horizons/${PORTVERSION}/

MAINTAINER=		fiziologus@gmail.com
COMMENT=		Real time simulation game

BUILD_DEPENDS=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl \
			${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=		${PYTHON_SITELIBDIR}/fife/__init__.py:${PORTSDIR}/games/py-fife \
			${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
			${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml \
			${PYTHON_PKGNAMEPREFIX}gdbm>0:${PORTSDIR}/databases/py-gdbm

WRKSRC=			${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=		i386 amd64

USE_XZ=			yes
USE_GNOME=		intltool
USES=			gettext:build
USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	UnknownHorizons

MAN6=			unknown-horizons.6

NO_STAGE=	yes
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
	${REINPLACE_CMD} -e "s|http://docbook.sourceforge.net/release/xsl/current|${LOCALBASE}/share/xsl/docbook|" \
		-e "s|share/man/man6|man/man6|" ${WRKSRC}/setup.py

# Install multiplayer lib (enet+pyenet)
post-install:
	${MKDIR} ${PYTHON_SITELIBDIR}/horizons/network/libs
	${MKDIR} ${PYTHON_SITELIBDIR}/horizons/network/libs/freebsd-${ENET_DIR}
	${INSTALL} ${WRKSRC}/horizons/network/libs/freebsd-${ENET_DIR}/enet.so \
		${PYTHON_SITELIBDIR}/horizons/network/libs/freebsd-${ENET_DIR}/enet.so

.include <bsd.port.post.mk>
