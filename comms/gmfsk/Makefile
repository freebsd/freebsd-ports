# New ports collection makefile for:   gmfsk
# Date created:                29th May 2003
# Whom:                        Carl Makin <carl@stagecraft.cx>
#
# $FreeBSD$
#

PORTNAME=	gmfsk
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	comms audio
MASTER_SITES=	http://gmfsk.connect.fi/

MAINTAINER=	carl@stagecraft.cx
COMMENT=	The Gnome MFSK terminal program

LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw

GNU_CONFIGURE=	yes
# This is pure evil but it looks like autoconf 2.53 has a bug in linking the
# preprocessor include tests.  The following line is a work around.
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"
USE_GMAKE=	yes
USE_GNOME=	libgnomeui gnomehack gnomeprefix
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

OPTIONS=	HAMLIB "Enable HAMLIB Support" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_HAMLIB)
LIB_DEPENDS+=	hamlib:${PORTSDIR}/comms/hamlib
CONFIGURE_ARGS+=	--enable-hamlib
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${LOCALBASE}/lib/pkgconfig
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[$$][(]localstatedir[)]/lib/scrollkeeper|${SCROLLKEEPER_DIR}|g' \
		${WRKSRC}/omf.make ${WRKSRC}/help/gmfsk/C/Makefile.in

post-install:
	@${CAT} pkg-message

.include <bsd.port.post.mk>
