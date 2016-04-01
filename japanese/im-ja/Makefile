# Created by: Jacques Vidrine <nectar@FreeBSD.org>
# $FreeBSD$

PORTNAME=	im-ja
PORTVERSION=	1.5
PORTREVISION=	12
CATEGORIES=	japanese x11-toolkits
MASTER_SITES=	http://im-ja.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese input module for GTK2

OPTIONS_DEFINE=	ANTHY CANNA WNN
OPTIONS_DEFAULT=ANTHY CANNA WNN
ANTHY_DESC=	Use Anthy
CANNA_DESC=	Use Canna
WNN_DESC=	Use FreeWnn

USES=		gettext gmake libtool pathfix perl5 pkgconfig
USE_GNOME=	gconf2 gnomeprefix intlhack libglade2
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-schemas-install # Avoid stage violation
CONFIGURE_ARGS+=	--disable-gnome

GCONF_SCHEMAS=	im-ja.schemas

CPPFLAGS+=	-I${LOCALBASE}/include -DNO_MALLOC_H
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MANTHY}
LIB_DEPENDS+=	libanthy.so:japanese/anthy
.else
CONFIGURE_ARGS+=	--disable-anthy
.endif

.if ${PORT_OPTIONS:MCANNA}
LIB_DEPENDS+=	libRKC.so:japanese/canna-lib
.else
CONFIGURE_ARGS+=	--disable-canna
.endif

.if ${PORT_OPTIONS:MWNN}
LIB_DEPENDS+=	libwnn.so:japanese/FreeWnn-lib
.else
CONFIGURE_ARGS+=	--disable-wnn
.endif

post-patch:
	${FIND} ${WRKSRC} -name configure.in | ${XARGS} ${TOUCH}
	${FIND} ${WRKSRC} -name aclocal.m4 | ${XARGS} ${TOUCH}
	${FIND} ${WRKSRC} -name configure | ${XARGS} ${TOUCH}
	${FIND} ${WRKSRC} -name config.h.in | ${XARGS} ${TOUCH}
	${FIND} ${WRKSRC} -name Makefile.am | ${XARGS} ${TOUCH}
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${TOUCH}
	@${REINPLACE_CMD} -e 's|$$(datadir)/gconf|$$(sysconfdir)/gconf|g' \
		${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} '/^im_ja_la_LIBADD =/s/$$/ -lm/' \
		${WRKSRC}/src/gtk/Makefile.in
	@${REINPLACE_CMD} '/^im_ja_helper_LDADD =/s/$$/ -lX11/' \
		${WRKSRC}/src/helper/Makefile.in
	@${REINPLACE_CMD} '/^im_ja_le_la_LIBADD =/s/$$/ -lm/' \
		${WRKSRC}/src/iiimf/Makefile.in
	@${REINPLACE_CMD} '/^im_ja_xim_server_LDADD =/s/$$/ -lm/' \
		${WRKSRC}/src/xim/Makefile.in

.include <bsd.port.mk>
