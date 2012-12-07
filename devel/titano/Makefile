# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	titano
PORTVERSION=	0.0.7
PORTREVISION=	9
CATEGORIES=	devel gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An IDE for GNOME desktop

DEPRECATED=	Dead upstream since 2001
EXPIRATION_DATE=	2013-01-07

LIB_DEPENDS=	unicode:${PORTSDIR}/devel/libunicode

USE_GNOME=	gnomelibs libglade
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

EXTRA_PATCHES+=	${FILESDIR}/gcc3-*

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif

pre-patch: .SILENT
	${REINPLACE_CMD} -e 's|malloc\.h|stdlib\.h|' \
		${WRKSRC}/src/scintilla/PosRegExp.cxx
	${REINPLACE_CMD} -e 's|^INCLUDES.*$$|&$$(LIBGLADE_CFLAGS)|' \
		${WRKSRC}/src/Makefile.in
	${REINPLACE_CMD} -E 's|(POTFILES\.in )\\$$|\1--from-code=koi8-r \\|' \
		${WRKSRC}/po/Makefile.in.in
# Now, take care of CC/CFLAGS
	${REINPLACE_CMD} -e 's|cc -Wall -ggdb $$(OPTIMIZE)|${CC} ${CFLAGS}|' \
		${WRKSRC}/src/gtkeditor/tktext-port/Makefile
	${REINPLACE_CMD} -e 's|gcc|${CC} ${CFLAGS}|' \
		${WRKSRC}/src/scanners/Makefile.in
	${REINPLACE_CMD} -E 's|^(CXXFLAGS).*$$|\1 += -DGTK -DSCI_LEXER|' \
		${WRKSRC}/src/scintilla/Makefile.in

.include <bsd.port.post.mk>
