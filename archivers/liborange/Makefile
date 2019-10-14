# Created by: Sam Lawrance <boris@brooknet.com.au>
# $FreeBSD$

PORTNAME=	liborange
PORTVERSION=	0.4
PORTREVISION=	7
CATEGORIES=	archivers
MASTER_SITES=	SF/synce/Orange/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to extract CAB files from self-extracting installers

LIB_DEPENDS=	libgsf-1.so:devel/libgsf
RUN_DEPENDS=	cabextract:archivers/cabextract

OPTIONS_DEFINE=	LIBDYNAMITE LIBUNSHIELD INNO VISE MSI
OPTIONS_DEFAULT=	LIBDYNAMITE LIBUNSHIELD
LIBDYNAMITE_DESC=	PKWARE data compression support via libdynamite
LIBUNSHIELD_DESC=	InstallShield support via libunshield
INNO_DESC=		Expermential Inno Setup support
VISE_DESC=		Expermential VISE support
MSI_DESC=		Expermential MSI support

USES=		iconv libtool localbase pathfix pkgconfig
LIBS+=		-lgsf-1
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS+=		--with-libgsf

LIBDYNAMITE_LIB_DEPENDS=	libdynamite.so:archivers/libdynamite
LIBDYNAMITE_CONFIGURE_WITH=	libdynamite
LIBDYNAMITE_VARS=		REQUIRES+=libdynamite

LIBUNSHIELD_LIB_DEPENDS=	libunshield.so:archivers/unshield
LIBUNSHIELD_CONFIGURE_WITH=	libunshield
LIBUNSHIELD_VARS=		REQUIRES+=libunshield

INNO_CONFIGURE_ENABLE=		inno

VISE_CONFIGURE_ENABLE=		vise

MSI_CONFIGURE_ENABLE=		msi

post-patch:
.for req in ${REQUIRES}
	@${REINPLACE_CMD} -e 's|${req}||' ${WRKSRC}/${PORTNAME}.pc.in
.endfor

.include <bsd.port.mk>
