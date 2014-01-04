# Created by: Jacques Vidrine <nectar@FreeBSD.org>
# $FreeBSD$

PORTNAME=	im-ja
PORTVERSION=	1.5
PORTREVISION=	10
CATEGORIES=	japanese x11-toolkits
MASTER_SITES=	http://im-ja.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese input module for GTK2

OPTIONS_DEFINE=	ANTHY CANNA WNN GNOMEPANEL
OPTIONS_DEFAULT=	ANTHY CANNA WNN
ANTHY_DESC=		Use Anthy
CANNA_DESC=		Use Canna
WNN_DESC=		Use FreeWnn
GNOMEPANEL_DESC=	Build GNOME Panel Applet

USES=		gmake pathfix perl5 pkgconfig
USE_GNOME=	gconf2 gnomeprefix intlhack libglade2
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-schemas-install # Avoid stage violation

GCONF_SCHEMAS=	im-ja.schemas

CPPFLAGS+=	-I${LOCALBASE}/include -DNO_MALLOC_H
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MANTHY}
LIB_DEPENDS+=	libanthy.so:${PORTSDIR}/japanese/anthy
.else
CONFIGURE_ARGS+=	--disable-anthy
.endif

.if ${PORT_OPTIONS:MCANNA}
LIB_DEPENDS+=	libRKC.so:${PORTSDIR}/japanese/canna-lib
.else
CONFIGURE_ARGS+=	--disable-canna
.endif

.if ${PORT_OPTIONS:MWNN}
LIB_DEPENDS+=	libwnn.so:${PORTSDIR}/japanese/FreeWnn-lib
.else
CONFIGURE_ARGS+=	--disable-wnn
.endif

.if ${PORT_OPTIONS:MGNOMEPANEL}
USE_GNOME+=	gnomepanel
PLIST_SUB+=	GNOMEPANEL=""
.else
CONFIGURE_ARGS+=	--disable-gnome
PLIST_SUB+=	GNOMEPANEL="@comment "
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

.include <bsd.port.mk>
