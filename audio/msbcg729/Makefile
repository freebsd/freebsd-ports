# $FreeBSD$

PORTNAME=	msbcg729
PORTVERSION=	1.0.2
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH/linphone/plugins/sources
DISTNAME=	bcg729-${DISTVERSION}

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Software G729A codec plugin for Mediastreamer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libortp.so:net/ortp \
		libmediastreamer_base.so:net/mediastreamer

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --disable-strict
INSTALL_TARGET=	install-strip
USES=		libtool pkgconfig

post-patch:
# Don't install libbcg729 (provided by audio/bcg729).
	@${REINPLACE_CMD} \
		-e '/^LTLIBRARIES =/s/lib_LTLIBRARIES/noinst_LTLIBRARIES/' \
		-e 's/^lib_LTLIBRARIES/noinst_LTLIBRARIES/' \
		-e 's/-rpath $$(libdir)//' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
