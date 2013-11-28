# Created by: Quentin Stievenart <acieroid@awesom.eu>
# $FreeBSD$

PORTNAME=	zathura
PORTVERSION=	0.2.5
CATEGORIES=	graphics print
MASTER_SITES=	http://pwmt.org/projects/zathura/download/

MAINTAINER=	acieroid@awesom.eu
COMMENT=	Customizable lightweight pdf viewer

LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libgirara-gtk3.so:${PORTSDIR}/x11-toolkits/girara
BUILD_DEPENDS+=	rst2html:${PORTSDIR}/textproc/py-docutils

USE_GNOME=	glib20 gtk30
USES=		gmake pkgconfig
MAKE_ENV=	SFLAGS="${STRIP}" \
		RSTTOMAN=${LOCALBASE}/bin/rst2man

OPTIONS_DEFINE=	NLS SQLITE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE}
LIB_DEPENDS+=	libsqlite3.so:${PORTSDIR}/databases/sqlite3
MAKE_ENV+=	WITH_SQLITE=1
.else
MAKE_ENV+=	WITH_SQLITE=0
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|man[15]|man/&|g' \
		-e 's|$${LIBDIR}/pkgconfig|${PREFIX}/libdata/pkgconfig|g'\
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|PLUGINDIR ?= .*$$|PLUGINDIR ?= ${PREFIX}/lib/zathura|'\
		${WRKSRC}/config.mk
.if ! ${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e '/-C po/d'\
		${WRKSRC}/Makefile
.endif
	${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		-e 's/-lpthread/${PTHREAD_LIBS}/' \
		-e 's/-lc//' \
		-e 's/DL_LIB /#&/' \
		${WRKSRC}/config.mk
	${REINPLACE_CMD} -e 's|/etc|${PREFIX}&|g' \
		${WRKSRC}/config.h \
		${WRKSRC}/zathurarc.5.rst
	(cd ${WRKSRC}; ${RM} -f zathura.1 zathurarc.5)

.include <bsd.port.mk>
