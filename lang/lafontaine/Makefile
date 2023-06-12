PORTNAME=	lafontaine
DISTVERSION=	0.4-1
PORTREVISION=	11
CATEGORIES=	lang
MASTER_SITES=	http://www.nongnu.org/lafontaine/archives/
DISTNAME=	lafontaine_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical logo interpreter
WWW=		https://www.nongnu.org/lafontaine/en/eubaout.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		gmake gnome pathfix pkgconfig
USE_CSTD=	gnu89
USE_GNOME=	cairo gdkpixbuf2 gtk20
GNU_CONFIGURE=	yes
LDFLAGS+=	-lm
WRKSRC=		${WRKDIR}/${PORTNAME}-0.4

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.mk>
