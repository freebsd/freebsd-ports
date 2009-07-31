# New ports collection makefile for:	gtick
# Date created:		10 February 2004
# Whom:			Liam J. Foy <liamfoy@sepulcrum.org>
#
# $FreeBSD$
#

PORTNAME=	gtick
PORTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.antcom.de/gtick/download/ CENKES

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	A metronome application

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	gtick.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

.include <bsd.port.mk>
