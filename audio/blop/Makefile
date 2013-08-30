# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	blop
PORTVERSION=	0.2.8
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bandlimited oscillator plugins for LADSPA-aware audio applications

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ladspa-prefix="${LOCALBASE}"

OPTIONS_DEFINE=	NLS

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(LIBS)$$|$$(LIBS) $$(LDFLAGS)|g ; \
		 s|-lc | |g'

.include <bsd.port.mk>
