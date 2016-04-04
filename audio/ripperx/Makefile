# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	ripperx
PORTVERSION=	2.7.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	ripperX-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK program to rip CD audio tracks and encode them

LIB_DEPENDS=	libid3.so:audio/id3lib
RUN_DEPENDS=	cdparanoia:audio/cdparanoia

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_lib_id3_ID3Tag_Link=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gmake pathfix pkgconfig
USE_GNOME=	gtk20

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} 's/-lstdc++/-lm/' ${WRKSRC}/configure
	@${REINPLACE_CMD} '/^CCLD =/s/=.*/= $$(CXX)/' \
		${WRKSRC}/plugins/Makefile.in ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
