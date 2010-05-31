# New ports collection makefile for:	rubrica
# Date created:		27 February 2003
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	rubrica
PORTVERSION=	2.0.8
PORTREVISION=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	BERLIOS
DISTNAME=	${PORTNAME}2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An addressbook for the GNOME 2 desktop

LIB_DEPENDS=	notify.1:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme

USE_BZIP2=	yes
USE_GNOME=	gconf2 gnomehack gnomeprefix libglade2
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

GCONF_SCHEMAS=	rubrica2.schemas

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-Wall -g|-Wall|g ; \
		 s|-Wmissing-prototypes -g|-Wmissing-prototypes|g'
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g' ${WRKSRC}/Makefile.in

post-install:
	@${LN} -sf ${LOCALBASE}/share/icons/gnome \
		${PREFIX}/share/pixmaps/rubrica2/22x22/hicolor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS CREDITS ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${PREFIX}/share/doc/libRAL
	${INSTALL_DATA} ${WRKSRC}/doc/reference/html/*.* \
		${PREFIX}/share/doc/libRAL
.endif

.include <bsd.port.mk>
