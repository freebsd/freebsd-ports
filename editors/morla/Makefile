PORTNAME=	morla
PORTVERSION=	0.16.1
PORTREVISION=	14
CATEGORIES=	editors textproc
MASTER_SITES=	http://www.morlardf.net/src/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	RDF editor
WWW=		http://www.morlardf.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Project is unmaintained and last upstream release was in 2011
EXPIRATION_DATE=	2024-03-31

BUILD_DEPENDS=	dot:graphics/graphviz
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libnxml.so:textproc/libnxml \
		libraptor2.so:textproc/raptor2 \
		librasqal.so:textproc/rasqal \
		librdf.so:textproc/redland
RUN_DEPENDS=	dot:graphics/graphviz

USES=		gettext gnome libtool localbase:ldflags pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk20 libxslt
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gconf=none --with-gtkhtml=none

DESKTOP_ENTRIES="morla" \
		"Edit RDF documents" \
		"${DATADIR}/icons/128_color.png" \
		"morla" \
		"WebDevelopment;" \
		true

OPTIONS_DEFINE=	XULRUNNER

XULRUNNER_DESC=	Xulrunner as JavaScript engine

XULRUNNER_BROKEN=	www/libxul is gone, consider using lang/spidermonkey*
XULRUNNER_CONFIGURE_ON=	--with-javascript=xulrunner
XULRUNNER_CONFIGURE_OFF=	--with-javascript=none

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
