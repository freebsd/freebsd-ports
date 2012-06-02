# New ports collection makefile for: unknown-horizons
# Date created:      26 May 2012
# Whom:              GreenDog <fiziologus@gmail.com>
#
# $FreeBSD$

PORTNAME=		unknown-horizons
PORTVERSION=		2012.1
CATEGORIES=		games
MASTER_SITES=		SF/unknownhorizons/Unknown%20Horizons/${PORTVERSION}/

MAINTAINER=		fiziologus@gmail.com
COMMENT=		Real time simulation game

BUILD_DEPENDS=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl \
			${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=		${PYTHON_SITELIBDIR}/fife/__init__.py:${PORTSDIR}/games/py-fife \
			${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3 \
			${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml \
			${PYTHON_SITELIBDIR}/gdbm.so:${PORTSDIR}/databases/py-gdbm

WRKSRC=			${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=		i386 amd64

USE_XZ=			yes
USE_GNOME=		intltool
USE_GETTEXT=		build
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	UnknownHorizons

MAN6=			unknown-horizons.6

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
PLIST_SUB+=     X86_ONLY=""
.else
PLIST_SUB+=     X86_ONLY="@comment "
.endif

.if ${ARCH} == amd64
PLIST_SUB+=     X64_ONLY=""
.else
PLIST_SUB+=     X64_ONLY="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e "s|http://docbook.sourceforge.net/release/xsl/current|${LOCALBASE}/share/xsl/docbook|" \
		-e "s|share/man/man6|man/man6|" ${WRKSRC}/setup.py

.include <bsd.port.post.mk>
