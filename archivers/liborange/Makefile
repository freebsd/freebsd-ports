# Created by: Sam Lawrance <boris@brooknet.com.au>
# $FreeBSD$

PORTNAME=	liborange
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	SF/synce/Orange/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to extract CAB files from self-extracting installers

LIB_DEPENDS=	libgsf-1.so:devel/libgsf
RUN_DEPENDS=	cabextract:archivers/cabextract \
		unzip:archivers/unzip

OPTIONS_DEFINE=	LIBSYNCE LIBDYNAMITE LIBUNSHIELD INNO VISE MSI
OPTIONS_DEFAULT=	LIBSYNCE LIBDYNAMITE LIBUNSHIELD
LIBSYNCE_DESC=		WinCE communication support via libsynce
LIBDYNAMITE_DESC=	PKWARE data compression support via libdynamite
LIBUNSHIELD_DESC=	InstallShield support via libunshield
INNO_DESC=		Expermential Inno Setup support
VISE_DESC=		Expermential VISE support
MSI_DESC=		Expermential MSI support

GNU_CONFIGURE=	yes
USES=		iconv libtool localbase pathfix pkgconfig
LIBS+=		-lgsf-1
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS+=		--with-libgsf

LIBSYNCE_LIB_DEPENDS=		libsynce.so:palm/synce-libsynce
LIBSYNCE_CONFIGURE_WITH=	libsynce
LIBSYNCE_VARS=			REQUIRES+=libsynce

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
