# New ports collection makefile for:	buoh
# Date created:				10 November 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/deskutils/buoh/Makefile,v 1.1 2006/10/23 21:43:08 mezz Exp $
#

PORTNAME=	buoh
PORTVERSION=	0.8.2
PORTREVISION=	2
CATEGORIES=	deskutils www gnome
MASTER_SITES=	http://buoh.steve-o.org/downloads/

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A reader for online strips comics

LIB_DEPENDS=	soup-2.2.8:${PORTSDIR}/devel/libsoup

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui
USE_XLIB=	yes
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

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not build on 4.X
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

.include <bsd.port.post.mk>
