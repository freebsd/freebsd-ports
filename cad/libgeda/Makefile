# New ports collection makefile for:	libgeda
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	libgeda
PORTVERSION=	1.4.3
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/release/v1.4/${PORTVERSION}/ \
		http://geda.seul.org/release/v1.4/${PORTVERSION}/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	The gEDA's tools base utility library

LIB_DEPENDS=	guile.20:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomehack
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-update-mime-database \
		--disable-update-desktop-database
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s,^(DATADIR[[:space:]]*=[[:space:]]*)gEDA,\1geda," \
		${WRKSRC}/configure

.include <bsd.port.mk>
