# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	patchage
PORTVERSION=	0.5.0
PORTREVISION=	20
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/ \
		http://frugalware.mirrors.tds.net/pub/linux/frugalware/frugalware-current/source/xmultimedia-extra/patchage/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular patch bay for Jack

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjack.so:audio/jack \
		libraul.so:audio/raul \
		libboost_date_time.so:devel/boost-libs \
		libdbus-glib-1.so:devel/dbus-glib \
		libglibmm-2.4.so:devel/glibmm \
		libglademm-2.4.so:devel/libglademm24 \
		libflowcanvas.so:x11-toolkits/flowcanvas

USES=		compiler:c++11-lang gnome pkgconfig tar:bzip2 waf
USE_CXXSTD=	c++11
INSTALLS_ICONS=	yes
CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man \
			--no-alsa \
			--no-lash

CFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e \
		"s|$$[{]LIBDIRNAME[}]/pkgconfig|libdata/pkgconfig| ; \
		 s|-fshow-column'|-fshow-column ${CXXFLAGS}'|" \
			${WRKSRC}/autowaf/autowaf.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
