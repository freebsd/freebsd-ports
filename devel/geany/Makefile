# New ports collection Makefile for:	geany
# Date Created:				15 Jan 06
# Whom:					Remington Lang <MrL0Lz@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	geany
PORTVERSION=	0.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	MrL0Lz@gmail.com
COMMENT=	A fast and lightweight GTK+ IDE

USE_X_PREFIX=	no
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	VTE "With vte" On

MAN1=	geany.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITHOUT_VTE)
CONFIGURE_ARGS+=--disable-vte
.else
USE_GNOME+=	vte
CONFIGURE_ARGS+=--enable-vte
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC} ${CFLAGS}|' ${WRKSRC}/scintilla/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|doc||' ${WRKSRC}/Makefile.in
.endif
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|po||' ${WRKSRC}/Makefile.in
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/geany.desktop ${PREFIX}/share/applications

.if ${OSVERSION} < 500036
EXTRA_PATCHES+=	${PATCHDIR}/extra-*
.endif

.include <bsd.port.post.mk>
