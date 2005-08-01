# New ports collection makefile for:	im-ja
# Date created:				2003/09/02
# Whom:					Jacques Vidrine <nectar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	im-ja
PORTVERSION=	1.4
CATEGORIES=	japanese x11-toolkits
MASTER_SITES=	http://im-ja.sourceforge.net/

MAINTAINER=	nectar@FreeBSD.org
COMMENT=	A Japanese input module for GTK2

OPTIONS+=	ANTHY	"Use Anthy" on
OPTIONS+=	CANNA	"Use Canna" on
OPTIONS+=	WNN	"Use FreeWnn" on

USE_PERL5_BUILD=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomeprefix gnomehack gnomepanel lthack
GNU_CONFIGURE=	yes

LIBS+=		-L${LOCALBASE}/lib -L${X11BASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
CPPFLAGS+=	-DNO_MALLOC_H
CONFIGURE_ENV+=	LIBS="${LIBS}" CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+=	INTLTOOL_PERL="${PERL}"

MAN1=		im-ja-conf.1 im-ja-xim-server.1

.include <bsd.port.pre.mk>

.if defined(WITHOUT_ANTHY)
CONFIGURE_ARGS+=	--disable-anthy
.else
LIB_DEPENDS+=	anthy.1:${PORTSDIR}/japanese/anthy
.endif
.if defined(WITHOUT_CANNA)
CONFIGURE_ARGS+=	--disable-canna
.else
LIB_DEPENDS+=	RKC.1:${PORTSDIR}/japanese/Canna
.endif
.if defined(WITHOUT_WNN)
CONFIGURE_ARGS+=	--disable-wnn
.else
LIB_DEPENDS+=	wnn.0:${PORTSDIR}/japanese/FreeWnn-lib
.endif

post-patch:
	${FIND} ${WRKSRC} -name configure.in | ${XARGS} ${TOUCH}
	${FIND} ${WRKSRC} -name aclocal.m4 | ${XARGS} ${TOUCH}
	${FIND} ${WRKSRC} -name configure | ${XARGS} ${TOUCH}
	${FIND} ${WRKSRC} -name config.h.in | ${XARGS} ${TOUCH}
	${FIND} ${WRKSRC} -name Makefile.am | ${XARGS} ${TOUCH}
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${TOUCH}

post-install:
	${X11BASE}/bin/gtk-query-immodules-2.0 > \
	    ${X11BASE}/etc/gtk-2.0/gtk.immodules

.include <bsd.port.post.mk>
