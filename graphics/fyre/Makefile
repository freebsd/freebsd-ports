# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fyre
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://releases.navi.cx/fyre/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chaos map rendering system with GTK+-2 interface

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS OPENEXR GNET DOCS
OPTIONS_DEFAULT=	OPENEXR GNET
OPENEXR_DESC=	Enable OpenEXR suport
GNET_DESC=	Enable GNet support

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		gmake pkgconfig
USE_BZIP2=	yes
USE_GNOME=	desktopfileutils libglade2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && !empty(PORT_OPTIONS:MOPT_CFLAGS)
CFLAGS+=	-march=native -O3 -ffast-math -fomit-frame-pointer
.endif

.if ${PORT_OPTIONS:MOPENEXR}
LIB_DEPENDS+=	IlmImf:${PORTSDIR}/graphics/OpenEXR
.else
CONFIGURE_ARGS+=--disable-openexr
.endif

.if ${PORT_OPTIONS:MGNET}
LIB_DEPENDS+=	gnet-2.0.0:${PORTSDIR}/net/gnet2
.else
CONFIGURE_ARGS+=--disable-gnet
.endif

post-patch:
	@${REINPLACE_CMD} -e '/-O3/s|^|#|g' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@-update-desktop-database

.include <bsd.port.post.mk>
