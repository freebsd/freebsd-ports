# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	blop
PORTVERSION=	0.2.8
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bandlimited oscillator plugins for LADSPA-aware audio applications

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ladspa-prefix="${LOCALBASE}"

OPTIONS_DEFINE=	NLS

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(LIBS)$$|$$(LIBS) $$(LDFLAGS)|g ; \
		 s|-lc | |g'

.include <bsd.port.mk>
