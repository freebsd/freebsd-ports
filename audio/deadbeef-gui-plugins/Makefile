PORTNAME=	deadbeef
PORTVERSION=	0.7.2
CATEGORIES=	audio misc
MASTER_SITES=	SF/${PORTNAME}/Archive
PKGNAMESUFFIX=	-${FLAVOR}-gui-plugins

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GUI plugins for DeaDBeeF audio player
WWW=		https://deadbeef.sourceforge.io/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libjansson.so:devel/jansson
RUN_DEPENDS=	${PORTNAME}:${CATEGORIES:[1]}/${PORTNAME}

USES=		gettext-tools gmake gnome libtool pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${_DISABLE_UNNEEDED_PLUGINS:sh}
USE_GNOME=	intltool
INSTALL_TARGET=	install-strip

FLAVORS=	gtk2 gtk3

.if ${FLAVOR:U} == gtk3
CONFIGURE_ARGS+=	--disable-gtk2
USE_GNOME+=	gtk30
PLIST_SUB+=	GTK_VER=3
.else
CONFIGURE_ARGS+=	--disable-gtk3
USE_GNOME+=	gtk20
PLIST_SUB+=	GTK_VER=2
.endif

OPTIONS_DEFINE=	NLS

NLS_CONFIGURE_OFF=	--disable-nls

post-patch:
	@${REINPLACE_CMD} -e 's, -a.*shellexec.*",,' ${WRKSRC}/configure

_FILTER_OUT_ENTRIES=	abstract-socket converter gtk pltbrowser \
			portable shellexecui staticlink
_DISABLE_UNNEEDED_PLUGINS=	${SED} -n "/^enable_nullout/,/^'/ { \
	s,^en,--dis,; s,_,-,g p; }" ${WRKSRC}/configure | \
	${EGREP} -v '${_FILTER_OUT_ENTRIES:ts|}'

.include <bsd.port.mk>
