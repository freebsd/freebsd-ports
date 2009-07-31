# New ports collection makefile for:   xarchiver
# Date created:        27 Mart 2008
# Whom:            Andreev Maxim
#
# $FreeBSD$
#

PORTNAME=	xarchiver
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	SF

MAINTAINER=	andreevmaxim@gmail.com
COMMENT=	Desktop-agnostic GTK+2 frontend to various archiving tools

RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 intltool pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|doc||g' ${WRKSRC}/Makefile.in
.endif
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e 's| po | |g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
