PORTNAME=	ripperx
PORTVERSION=	2.7.3
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	ripperX-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK program to rip CD audio tracks and encode them
WWW=		https://sourceforge.net/projects/ripperx/

LIB_DEPENDS=	libid3.so:audio/id3lib
RUN_DEPENDS=	cdparanoia:audio/cdparanoia

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_lib_id3_ID3Tag_Link=yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		compiler:c++11-lang gmake gnome pkgconfig
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
