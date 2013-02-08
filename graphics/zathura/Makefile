# Created by: Quentin Stievenart <acieroid@awesom.eu>
# $FreeBSD$

PORTNAME=	zathura
PORTVERSION=	0.2.2
CATEGORIES=	graphics print
MASTER_SITES=	http://pwmt.org/projects/zathura/download/

MAINTAINER=	acieroid@awesom.eu
COMMENT=	Customizable lightweight pdf viewer

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo \
		girara-gtk2:${PORTSDIR}/x11-toolkits/girara

USE_GNOME=	glib20 gtk20
USE_GMAKE=	yes
MAKE_ENV=	SFLAGS="${STRIP}"

OPTIONS_DEFINE=	DOCS NLS SQLITE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE}
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
MAKE_ENV+=	WITH_SQLITE=1
.else
MAKE_ENV+=	WITH_SQLITE=0
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	rst2html:${PORTSDIR}/textproc/py-docutils
MAN1+=		zathura.1
MAN5+=		zathurarc.5
MAKE_ENV+=	RSTTOMAN=${LOCALBASE}/bin/rst2man
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
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
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's|install-manpages$$||'\
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|RSTTOMAN ?= /usr/bin/rst2man|RSTTOMAN ?= ""|'\
		${WRKSRC}/config.mk
.endif
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
	(cd ${WRKSRC}; ${RM} -f ${MAN1} ${MAN5})

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
