# Created by: Carl Makin <carl@stagecraft.cx>
# $FreeBSD$

PORTNAME=	gmfsk
PORTVERSION=	0.6
PORTREVISION=	13
CATEGORIES=	comms audio hamradio
MASTER_SITES=	http://gmfsk.connect.fi/ \
		http://he.fi/pub/ham/unix/linux/hfmodems/ \
		LOCAL/db

MAINTAINER=	carl@stagecraft.cx
COMMENT=	The Gnome MFSK terminal program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw.so:${PORTSDIR}/math/fftw

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES_CSTD=	gnu89
USES=		gmake pkgconfig pathfix
USE_GNOME=	libgnomeui gnomeprefix
INSTALLS_OMF=	yes

GCONF_SCHEMAS=	gmfsk.schemas

CPPFLAGS+=	-DFBSD_HAS_LOG2

OPTIONS_DEFINE=	HAMLIB
HAMLIB_DESC=	Enable HAMLIB Support
OPTIONS_DEFAULT=	HAMLIB

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MHAMLIB}
LIB_DEPENDS+=	libhamlib.so:${PORTSDIR}/comms/hamlib
CONFIGURE_ARGS+=	--enable-hamlib
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${LOCALBASE}/lib/pkgconfig
.else
CONFIGURE_ARGS+=	--disable-hamlib
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[$$][(]localstatedir[)]/lib/scrollkeeper|${SCROLLKEEPER_DIR}|g' \
		${WRKSRC}/omf.make ${WRKSRC}/help/gmfsk/C/Makefile.in

.include <bsd.port.post.mk>
