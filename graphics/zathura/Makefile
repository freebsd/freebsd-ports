# New ports collection makefile for:	zathura
# Date created:				29 June 2010
# Whom:					Quentin Stievenart <acieroid@awesom.eu>
#
# $FreeBSD$
#

PORTNAME=	zathura
PORTVERSION=	0.2.0
CATEGORIES=	graphics print
MASTER_SITES=	http://pwmt.org/projects/zathura/download/

MAINTAINER=	acieroid@awesom.eu
COMMENT=	Customizable lightweight pdf viewer

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo \
		girara-gtk2.1:${PORTSDIR}/x11-toolkits/girara

USE_GNOME=	glib20 gtk20
USE_GMAKE=	yes
MAKE_ENV=	SFLAGS="${STRIP}"
FETCH_ARGS=	-Fpr

OPTIONS=	SQLITE "Support sqlite database backend" off

.include <bsd.port.options.mk>

.if !defined(WITHOUT_SQLITE)
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
MAKE_ENV+=	WITH_SQLITE=1
.else
MAKE_ENV+=	WITH_SQLITE=0
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	rst2html:${PORTSDIR}/textproc/py-docutils
MAN1+=		zathura.1
MAN5+=		zathurarc.5
.endif

.if !defined(WITHOUT_NLS)
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
	${REINPLACE_CMD} -e 's|girara_debug("plugin.*$$||'\
		${WRKSRC}/plugin.c
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|install-manpages$$||'\
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|RSTTOMAN ?= /usr/bin/rst2man|RSTTOMAN ?= ""|'\
		${WRKSRC}/config.mk
.endif
.if defined(WITHOUT_NLS)
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

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
