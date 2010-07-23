# New ports collection makefile for:	zathura
# Date created:				29 June 2010
# Whom:					Quentin Stievenart <acieroid@awesom.eu>
#
# $FreeBSD$
#

PORTNAME=	zathura
PORTVERSION=	0.0.7
CATEGORIES=	graphics print
MASTER_SITES=	http://pwmt.org/zathura/download/

MAINTAINER=	acieroid@awesom.eu
COMMENT=	Customizable lightweight pdf viewer

LIB_DEPENDS=	poppler-glib.4:${PORTSDIR}/graphics/poppler-gtk	\
		cairo.2:${PORTSDIR}/graphics/cairo

USE_GNOME=	glib20 gtk20

MAN1=		zathura.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/zathura

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|man1|man/man1|g' \
		-e '/CC/s/-s[[:space:]]/${STRIP} /' \
		-e '/CFLAGS/!s/$${LDFLAGS}/$${CFLAGS} &/' \
		-e 's/{DFLAGS/{DEBUG_FLAGS/g' \
		-e 's/755/${BINMODE}/' \
		-e 's/644/${MANMODE}/' \
		-e '/echo[[:space:]]CC/d' \
		-e '/echo/!s/@//' \
		-e '/^all:/s/options//' \
		-e 's/\(include\)[[:space:]]\(.*\)/.\1 "\2"/' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		-e 's/-lpthread/${PTHREAD_LIBS}/' \
		-e 's/-lc//' \
		-e 's/$$(shell[[:space:]]\(.*\))/`\1`/' \
		${WRKSRC}/config.mk

.include <bsd.port.mk>
