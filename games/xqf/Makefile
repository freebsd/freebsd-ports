# New ports collection makefile for:	xqf
# Date created:				08 February 1999
# Whom:					steve farrell
#
# $FreeBSD$
#

PORTNAME=	xqf
PORTVERSION=	1.0.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Find quake servers

RUN_DEPENDS=	qstat:${PORTSDIR}/games/qstat

USE_X_PREFIX=	yes
USE_GNOME=	gnomehier gnometarget intlhack
USE_GETOPT_LONG=	yes
USE_GETTEXT=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN6=		xqf.6

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if defined(WITH_GTK2)
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--enable-gtk2
PKGNAMESUFFIX=	-gtk2
.else
USE_GNOME+=	gdkpixbuf
.endif

.if defined(WITH_GEOIP)
LIB_DEPENDS+=	GeoIP.4:${PORTSDIR}/net/GeoIP
.else
CONFIGURE_ARGS+=	--disable-geoip
.endif

.if !defined(WITHOUT_BZIP2)
CONFIGURE_ARGS+=	--enable-bzip2
.if !exists(/usr/bin/bzip2)
RUN_DEPENDS+=	bzip2:${PORTSDIR}/archivers/bzip2
.endif
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|: install-desktopDATA|:|g ; \
		 s|$$(datadir)/pixmaps|$$(pkgdatadir)/pixmaps|g'

post-install:
	${INSTALL_DATA} ${WRKSRC}/xqf.desktop \
		${PREFIX}/share/gnome/applications
	${INSTALL_DATA} ${WRKSRC}/pixmaps/xqf_32x32.png \
		${PREFIX}/share/gnome/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/xqfdocs.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
