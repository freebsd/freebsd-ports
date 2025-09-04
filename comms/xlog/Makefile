PORTNAME=	xlog
DISTVERSION=	2.0.25
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	SAVANNAH

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio logging application
WWW=		https://xlog.nongnu.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libhamlib.so:comms/hamlib \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gnome pkgconfig shared-mime-info
USE_GNOME=	cairo gdkpixbuf gtk20

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_c_compiler_gnu=no

DESKTOP_ENTRIES="${PORTNAME}" "${COMMENT}" "${PORTNAME}" \
	"${PORTNAME}" "Utility;" ${FALSE}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=deprecated-non-prototype
.endif

.include <bsd.port.post.mk>
