# New ports collection makefile for:	anyremote
# Date created:		2008-11-05
# Whom:			Alex Samorukov <samm@os2.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	anyremote
PORTVERSION=	4.18.1
CATEGORIES=	comms
MASTER_SITES=	SFP/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Remote control service over Bluetooth, infrared or tcp/ip networking

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--disable-xtest
.else
USE_XORG=	x11 xtst
.endif
MAKE_ARGS+=	LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		anyremote.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|(datadir)/man/man1|(mandir)/man1|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|xtext|xtest|g' ${WRKSRC}/configure
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/doc\/${PORTNAME}/d' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
