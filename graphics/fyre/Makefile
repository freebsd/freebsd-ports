# Created by: Adam Weinberger <adamw@FreeBSD.org>

PORTNAME=	fyre
PORTVERSION=	1.0.1
PORTREVISION=	22
CATEGORIES=	graphics
MASTER_SITES=	http://releases.navi.cx/fyre/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chaos map rendering system with GTK+-2 interface

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		compiler:c++11-lang desktop-file-utils gmake gnome pkgconfig \
		shared-mime-info tar:bzip2
USE_GNOME=	libglade2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS OPENEXR GNET DOCS
OPTIONS_DEFAULT=	OPENEXR GNET

OPENEXR_CONFIGURE_ENABLE=	openexr
OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr

GNET_DESC=		Networking support via GNet
GNET_CONFIGURE_ENABLE=	gnet
GNET_LIB_DEPENDS=	libgnet-2.0.so:net/gnet2

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && !empty(PORT_OPTIONS:MOPT_CFLAGS)
CFLAGS+=	-march=native -O3 -ffast-math -fomit-frame-pointer
.endif

post-patch:
	@${REINPLACE_CMD} -e '/-O3/s|^|#|g' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
