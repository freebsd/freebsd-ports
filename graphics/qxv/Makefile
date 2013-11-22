# Created by: cy
# $FreeBSD$

PORTNAME=	qxv
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES+=	graphics
MASTER_SITES=	http://labs.freehackers.org/attachments/download/422/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Qt 4 program that displays images of various formats

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		glib-2.0.0:${PORTSDIR}/devel/glib20 \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		icui18n:${PORTSDIR}/devel/icu \
		intl.9:${PORTSDIR}/devel/gettext \
		pcre.3:${PORTSDIR}/devel/pcre \
		pthread-stubs.0:${PORTSDIR}/devel/libpthread-stubs \
		expat.6:${PORTSDIR}/textproc/expat2 \
		xcb.2:${PORTSDIR}/x11/xcb

USES=		iconv qmake
USE_BZIP2=	yes
USE_XORG=	sm xrender xext x11 xau xdmcp ice
USE_QT4=	corelib gui moc_build uic_build rcc_build
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/

.include <bsd.port.mk>
