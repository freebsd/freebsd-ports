# New ports collection makefile for:   libcaca
# Date created:			11 January 2004
# Whom:				Vincent Tantardini <vinc@FreeBSD-fr.org>
#
# $FreeBSD$

PORTNAME=	libcaca
PORTVERSION=	0.7
CATEGORIES=	graphics
MASTER_SITES=	http://sam.zoy.org/projects/libcaca/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphics library that outputs text instead of pixels

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--program-prefix="" \
			--enable-ncurses

MAN1=		caca-config.1 cacademo.1 cacaview.1

.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=YES
.endif

.if defined(WITHOUT_IMLIB2)
CONFIGURE_ARGS+=	--disable-imlib2
.else
LIB_DEPENDS+=		Imlib2.2:${PORTSDIR}/graphics/imlib2
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_SLANG) || exists(${LOCALBASE}/lib/libslang.so)
LIB_DEPENDS+=		slang.1:${PORTSDIR}/devel/libslang
CONFIGURE_ARGS+=	--enable-slang
.endif

post-patch:
	${REINPLACE_CMD} -e 's,libcaca-dev,libcaca,g' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
