# New ports collection makefile for:	zathura
# Date created:				29 June 2010
# Whom:					Quentin Stievenart <acieroid@awesom.eu>
#
# $FreeBSD$
#

PORTNAME=	zathura
PORTVERSION=	0.1.2
CATEGORIES=	graphics print
MASTER_SITES=	http://pwmt.org/projects/zathura/download/

MAINTAINER=	acieroid@awesom.eu
COMMENT=	Customizable lightweight pdf viewer

LIB_DEPENDS=	poppler-glib.8:${PORTSDIR}/graphics/poppler-glib \
		cairo.2:${PORTSDIR}/graphics/cairo \
		girara-gtk2.0:${PORTSDIR}/x11-toolkits/girara

USE_GNOME=	glib20 gtk20
USE_GMAKE=	yes
FETCH_ARGS=	-Fpr

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

post-install:	.SILENT
	${CAT} pkg-message

.include <bsd.port.mk>
