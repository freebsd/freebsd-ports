# $FreeBSD$

PORTNAME=		ikona
DISTVERSION=		1.0
CATEGORIES=		graphics kde
MASTER_SITES=		KDE/stable/${PORTNAME}/${DISTVERSION}/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${DISTNAME}.cargo.vendor${EXTRACT_SUFX}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Icon editing companion

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/LICENSE

BUILD_DEPENDS=		rustc:lang/${RUST_DEFAULT}

USES=			cmake:noninja compiler:c++11-lang desktop-file-utils \
			gmake gnome iconv kde:5 pkgconfig qt:5 tar:xz
USE_GNOME=		cairo gdkpixbuf2 glib20 libxml2 pango
USE_KDE=		auth codecs config configwidgets coreaddons i18n \
			kirigami2 widgetsaddons
USE_QT=			core declarative gui network widgets xml \
			buildtools_build qmake_build

pre-configure:
	${CP} ${DISTDIR}/${DISTNAME}.cargo.vendor${EXTRACT_SUFX} ${WRKSRC}/ikona.cargo.vendor.tar.xz

.include <bsd.port.mk>
