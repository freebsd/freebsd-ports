# New ports collection makefile for:	gtkpod
# Date created: 			28 January 2003
# Whom: 				David Le Brun <david@dyn-ns.net>
#
# $FreeBSD$
#

PORTNAME=	gtkpod
PORTVERSION=	0.50
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	david@dyn-ns.net
COMMENT=	A GUI to upload songs and playlists to iPod

LIB_DEPENDS=	id3-3.8.2:${PORTSDIR}/audio/id3lib \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_X_PREFIX=	yes

USE_GMAKE=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

pre-configure:
# install locale correctly (share dir instead of lib dir)
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(libdir)/locale|(datadir)/locale|' \
		${WRKSRC}/po/Makefile.in.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
