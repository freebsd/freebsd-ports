# New ports collection Makefile for:	blop
# Date created:			15 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	blop
PORTVERSION=	0.2.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bandlimited oscillator plugins for LADSPA-aware audio applications

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-ladspa-prefix="${LOCALBASE}"

OPTIONS=	NLS "Native language support" on

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(LIBS)$$|$$(LIBS) $$(LDFLAGS)|g ; \
		 s|-lc | |g'

.include <bsd.port.post.mk>
