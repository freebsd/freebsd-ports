# New ports collection makefile for:	gxmame
# Date created:			04 Oct 2003
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	gxmame
DISTVERSION=	0.35beta2
PORTEPOCH=	1
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	GXmame is a GTK frontend for xmame

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	xmame:${PORTSDIR}/emulators/xmame

USE_X_PREFIX=	yes
USE_GNOME=	gtk20 intlhack gnomehack gnomeprefix
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-xmame-dir=${X11BASE}/share/xmame

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

MAN6=		gxmame.6

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS="-Wall.*||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(datadir)/doc|${PREFIX}/share/doc|' \
		${WRKSRC}/Makefile.in ${WRKSRC}/html/Makefile.in
	@${REINPLACE_CMD} -e 's|__GNUC___|__GNUC__|' ${WRKSRC}/src/common.h

.include <bsd.port.mk>
