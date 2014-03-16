# Created by: Alexander Botero-Lowry <alexbl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	esperanza
PORTVERSION=	0.4.0.20091017
PORTREVISION=	2
CATEGORIES=	audio
#MASTER_SITES=	http://exodus.xmms.se/~tru/esperanza/0.4/
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION:R}+git${PORTVERSION:E}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced Qt4 XMMS2 client

LICENSE=	GPLv2

LIB_DEPENDS=	libxmmsclient++.so:${PORTSDIR}/audio/cpp-xmms2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}+git${PORTVERSION:E}

USE_QT4=	gui xml network imageformats_run \
		qmake_build moc_build rcc_build uic_build
QT_NONSTANDARD=	yes
USES=		gmake pkgconfig tar:bzip2
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-growl
MAKE_ARGS=	INSTALL_ROOT="${STAGEDIR}"

PLIST_FILES=	bin/esperanza
DESKTOP_ENTRIES="Esperanza" "" "" "${PORTNAME}" "Audio;Player;" false

.include <bsd.port.mk>
