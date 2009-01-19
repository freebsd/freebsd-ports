# New ports collection makefile for:	anyremote
# Date created:		2008-11-05
# Whom:			Alex Samorukov <samm@os2.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	anyremote
PORTVERSION=	4.15
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Remote control service over Bluetooth,infrared or tcp/ip networking

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(NOPORTDOCS)
EXTRA_PATCHES=	${FILESDIR}/opt-nodocs-patch
.endif
.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--disable-xtest
.else
USE_XORG=	x11 xtst
.endif
MAKE_ARGS+=	LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		anyremote.1
MANCOMPRESSED=	yes

pre-build:
	cd ${WRKSRC} && ${MAKE} clean
post-patch:
	@${REINPLACE_CMD} -e 's|(datadir)/man/man1|(mandir)/man1|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
