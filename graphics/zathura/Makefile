# New ports collection makefile for:	zathura
# Date created:				29 June 2010
# Whom:					Quentin Stievenart <acieroid@awesom.eu>
#
# $FreeBSD$
#

PORTNAME=	zathura
PORTVERSION=	0.0.8.4
PORTREVISION=	1
CATEGORIES=	graphics print
MASTER_SITES=	http://pwmt.org/download/

MAINTAINER=	acieroid@awesom.eu
COMMENT=	Customizable lightweight pdf viewer

LIB_DEPENDS=	poppler-glib.6:${PORTSDIR}/graphics/poppler-gtk	\
		cairo.2:${PORTSDIR}/graphics/cairo

USE_GNOME=	glib20 gtk20
FETCH_ARGS=	-Fpr

MAN1=		zathura.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/zathura	\
		share/applications/zathura.desktop
PLIST_DIRSTRY=	share/applications

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	rst2html:${PORTSDIR}/textproc/py-docutils
MAN5+=		zathurarc.5
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|man[15]|man/&|g' \
		-e '/CC/s/$${SFLAGS}/${STRIP} /' \
		-e '/CFLAGS/!s/$${LDFLAGS}/$${CFLAGS} &/' \
		-e 's/{DFLAGS/{DEBUG_FLAGS/g' \
		-e 's/755/${BINMODE}/' \
		-e 's/644/${MANMODE}/' \
		-e '/echo[[:space:]]CC/d' \
		-e '/echo/!s/^\([[:space:]]*\)@/\1/' \
		-e '/^all:/s/options//' \
		-e 's/cp[[:space:]]$$</cp $$>/' \
		-e 's/\(include\)[[:space:]]\(.*\)/.\1 "\2"/' \
		${WRKSRC}/Makefile
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} 's|which rst2man|${FALSE}|' ${WRKSRC}/Makefile
.endif
	${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		-e 's/-lpthread/${PTHREAD_LIBS}/' \
		-e 's/-lc//' \
		-e 's/$$(shell[[:space:]]\(.*\))/`\1`/' \
		${WRKSRC}/config.mk
	${REINPLACE_CMD} -e 's|/etc|${PREFIX}&|g' \
		${WRKSRC}/config.def.h \
		${WRKSRC}/zathurarc.5.rst

.include <bsd.port.mk>
