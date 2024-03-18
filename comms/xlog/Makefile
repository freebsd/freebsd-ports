PORTNAME=	xlog
DISTVERSION=	2.0.24
PORTREVISION=	4
CATEGORIES=	comms hamradio
MASTER_SITES=	SAVANNAH

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio logging application
WWW=		https://xlog.nongnu.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhamlib.so:comms/hamlib \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2


USES=		compiler:c11 gnome pkgconfig shared-mime-info
USE_GNOME=	cairo gdkpixbuf2 gtk20
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CONFIGURE_ARGS=	--enable-mime-update
CONFIGURE_ENV+=	ac_cv_c_compiler_gnu=no

DESKTOP_ENTRIES="${PORTNAME}" "${COMMENT}" "${PORTNAME}" \
	"${PORTNAME}" "Utility;" false

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=deprecated-non-prototype
.endif

.include <bsd.port.post.mk>
