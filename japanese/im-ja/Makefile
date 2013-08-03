# Created by: Jacques Vidrine <nectar@FreeBSD.org>
# $FreeBSD$

PORTNAME=	im-ja
PORTVERSION=	1.5
PORTREVISION=	10
CATEGORIES=	japanese x11-toolkits
MASTER_SITES=	http://im-ja.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Japanese input module for GTK2

OPTIONS_DEFINE=	ANTHY CANNA WNN GNOMEPANEL
OPTIONS_DEFAULT=	ANTHY CANNA WNN
ANTHY_DESC=		Use Anthy
CANNA_DESC=		Use Canna
WNN_DESC=		Use FreeWnn
GNOMEPANEL_DESC=	Build GNOME Panel Applet

USES=        pathfix perl5
USE_GNOME=	gconf2 gnomeprefix intlhack libglade2
USE_PERL5=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		im-ja-conf.1 im-ja-xim-server.1
GCONF_SCHEMAS=	im-ja.schemas

CPPFLAGS+=	-I${LOCALBASE}/include -DNO_MALLOC_H
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MANTHY}
LIB_DEPENDS+=	anthy.1:${PORTSDIR}/japanese/anthy
.else
CONFIGURE_ARGS+=	--disable-anthy
.endif

.if ${PORT_OPTIONS:MCANNA}
LIB_DEPENDS+=	RKC.1:${PORTSDIR}/japanese/canna-lib
.else
CONFIGURE_ARGS+=	--disable-canna
.endif

.if ${PORT_OPTIONS:MWNN}
LIB_DEPENDS+=	wnn.0:${PORTSDIR}/japanese/FreeWnn-lib
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

post-install:
	${LOCALBASE}/bin/gtk-query-immodules-2.0 > \
	    ${LOCALBASE}/etc/gtk-2.0/gtk.immodules

.include <bsd.port.mk>
