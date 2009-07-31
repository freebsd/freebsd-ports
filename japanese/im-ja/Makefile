# New ports collection makefile for:	im-ja
# Date created:				2003/09/02
# Whom:					Jacques Vidrine <nectar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	im-ja
PORTVERSION=	1.5
PORTREVISION=	7
CATEGORIES=	japanese x11-toolkits
MASTER_SITES=	http://im-ja.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Japanese input module for GTK2

OPTIONS+=	ANTHY		"Use Anthy" on
OPTIONS+=	CANNA		"Use Canna" on
OPTIONS+=	WNN		"Use FreeWnn" on
OPTIONS+=	GNOMEPANEL	"Build GNOME Panel Applet" off

USE_GNOME=	gconf2 gnomehack gnomeprefix gnometarget intlhack libglade2
USE_PERL5_BUILD=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		im-ja-conf.1 im-ja-xim-server.1
GCONF_SCHEMAS=	im-ja.schemas

CPPFLAGS=	-I${LOCALBASE}/include -DNO_MALLOC_H
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITHOUT_ANTHY)
CONFIGURE_ARGS+=	--disable-anthy
.else
LIB_DEPENDS+=	anthy.1:${PORTSDIR}/japanese/anthy
.endif

.if defined(WITHOUT_CANNA)
CONFIGURE_ARGS+=	--disable-canna
.else
LIB_DEPENDS+=	RKC.1:${PORTSDIR}/japanese/canna-lib
.endif

.if defined(WITHOUT_WNN)
CONFIGURE_ARGS+=	--disable-wnn
.else
LIB_DEPENDS+=	wnn.0:${PORTSDIR}/japanese/FreeWnn-lib
.endif

.if defined(WITH_GNOMEPANEL)
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

.include <bsd.port.post.mk>
