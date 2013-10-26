# Created by: Carl Makin <carl@stagecraft.cx>
# $FreeBSD$

PORTNAME=	gmfsk
PORTVERSION=	0.6
PORTREVISION=	11
CATEGORIES=	comms audio hamradio
MASTER_SITES=	http://gmfsk.connect.fi/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	carl@stagecraft.cx
COMMENT=	The Gnome MFSK terminal program

LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw

GNU_CONFIGURE=	yes
# This is pure evil but it looks like autoconf 2.53 has a bug in linking the
# preprocessor include tests.  The following line is a work around.
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
USES=		gmake pkgconfig
USE_GNOME=	libgnomeui gnomehack gnomeprefix
INSTALLS_OMF=	yes

GCONF_SCHEMAS=	gmfsk.schemas

OPTIONS_DEFINE=	HAMLIB
HAMLIB_DESC=	Enable HAMLIB Support
OPTIONS_DEFAULT=	HAMLIB

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MHAMLIB}
LIB_DEPENDS+=	hamlib:${PORTSDIR}/comms/hamlib
CONFIGURE_ARGS+=	--enable-hamlib
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${LOCALBASE}/lib/pkgconfig
.else
CONFIGURE_ARGS+=	--disable-hamlib
.endif

.if ( ${OSVERSION} >= 802502 && ${OSVERSION} < 900000 ) || ${OSVERSION} >= 900027
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-misc_misc.c
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-misc_misc.h
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[$$][(]localstatedir[)]/lib/scrollkeeper|${SCROLLKEEPER_DIR}|g' \
		${WRKSRC}/omf.make ${WRKSRC}/help/gmfsk/C/Makefile.in

post-install:
	@${CAT} pkg-message

.include <bsd.port.post.mk>
