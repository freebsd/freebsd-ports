# Created by: Sam Lawrance <boris@brooknet.com.au>
# $FreeBSD$

PORTNAME=	liborange
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	SF/synce/Orange/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to extract CAB files from self-extracting installers

RUN_DEPENDS=	cabextract:${PORTSDIR}/archivers/cabextract \
		unzip:${PORTSDIR}/archivers/unzip

OPTIONS_DEFINE=	LIBSYNCE LIBDYNAMITE LIBUNSHIELD INNO VISE MSI
OPTIONS_DEFAULT=	LIBSYNCE LIBDYNAMITE LIBUNSHIELD
LIBSYNCE_DESC=		Build with libsynce support
LIBDYNAMITE_DESC=	Build with libdynamite support
LIBUNSHIELD_DESC=	Build with libunshield support
INNO_DESC=		Build with expermential Inno Setup support
VISE_DESC=		Build with expermential VISE support
MSI_DESC=		Build with expermential MSI support

GNU_CONFIGURE=	yes
USES=		iconv libtool pathfix pkgconfig
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

LIBSYNCE_LIB_DEPENDS=		libsynce.so:${PORTSDIR}/palm/synce-libsynce
LIBSYNCE_CONFIGURE_WITH=	libsynce

LIBDYNAMITE_LIB_DEPENDS=	libdynamite.so:${PORTSDIR}/archivers/libdynamite
LIBDYNAMITE_CONFIGURE_WITH=	libdynamite

LIBUNSHIELD_LIB_DEPENDS=	libunshield.so:${PORTSDIR}/archivers/unshield
LIBUNSHIELD_CONFIGURE_WITH=	libunshield

INNO_CONFIGURE_ENABLE=		inno

VISE_CONFIGURE_ENABLE=		vise

MSI_LIB_DEPENDS=		libgsf-1.so.114:${PORTSDIR}/devel/libgsf
MSI_CONFIGURE_ENABLE=		msi libgsf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBSYNCE}
REQUIRES+=	libsynce
.endif

.if ${PORT_OPTIONS:MLIBDYNAMITE}
REQUIRES+=	libdynamite
.endif

.if ${PORT_OPTIONS:MLIBUNSHIELD}
REQUIRES+=	libunshield
.endif

post-patch:
.for req in ${REQUIRES}
	@${REINPLACE_CMD} -e 's|${req}||' ${WRKSRC}/${PORTNAME}.pc.in
.endfor

.include <bsd.port.mk>
