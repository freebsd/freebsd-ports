# New ports collection makefile for:	xqf
# Date created:				08 February 1999
# Whom:					steve farrell
#
# $FreeBSD$
#

PORTNAME=	xqf
PORTVERSION=	0.9.14
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Find quake servers

RUN_DEPENDS=	qstat:${PORTSDIR}/games/qstat

USE_GNOME=	gnometarget intlhack
USE_GETOPT_LONG=	yes
USE_GETTEXT=	yes
USE_REINPLACE=	yes
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
		's|: install-ApplicationsDATA|:|g ; \
		 s|$$(datadir)/pixmaps|$$(pkgdatadir)/pixmaps|g'

post-install:
	@${MKDIR} ${DATADIR}/pixmaps
	${INSTALL_DATA} ${WRKSRC}/pixmaps/xqf_48x48.png ${DATADIR}/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/xqfdocs.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
