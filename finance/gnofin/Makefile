# New ports collection makefile for:	gnofin
# Date created:				Sun Jul 18 1999
# Whom:					domi@saargate.de
#
# $FreeBSD$
#

PORTNAME=	gnofin
PORTVERSION=	0.8.4
PORTREVISION=	6
CATEGORIES=	finance deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Light-weight GNOME based financial management program

USE_XORG=	xpm sm
USE_GNOME=	gnomehack gnomelibs gnomeprefix
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=yes
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

MAN1=		gnofin.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g ; \
		s|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
			${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|_la_LDFLAGS =|_la_LDFLAGS = -avoid-version|g'
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%%GNOFIN_LIBDIR%%%|${PREFIX}/lib/gnofin/plugins|g' \
		${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
