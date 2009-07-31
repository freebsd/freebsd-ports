# New ports collection makefile for:	buoh
# Date created:				10 November 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/buoh/Makefile,v 1.5 2008/03/22 00:42:46 mezz Exp $
#

PORTNAME=	buoh
PORTVERSION=	0.8.2
PORTREVISION=	5
CATEGORIES=	deskutils www gnome
MASTER_SITES=	http://buoh.steve-o.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A reader for online strips comics

LIB_DEPENDS=	soup-2.2.8:${PORTSDIR}/devel/libsoup22

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=		AUTHORS COPYING ChangeLog NEWS README TODO
GCONF_SCHEMAS=	buoh.schemas

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
CFLAGS+=		-g
STRIP=
.endif

pre-everything::
.if !defined(WITH_DEBUG)
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} " "
	@${ECHO_MSG} "WITH_DEBUG=yes to enable debugging in Buoh."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[$$][(]datadir[)]/applications|${LOCALBASE}/share/applications|g' \
		${WRKSRC}/data/Makefile.in

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
