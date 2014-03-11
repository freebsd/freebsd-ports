# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/deskutils/nautilus-actions/Makefile,v 1.21 2010/04/16 23:41:09 kwm Exp $

PORTNAME=	nautilus-actions
PORTVERSION=	2.30.3
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extension for Nautilus to configure programs to launch on files

DEPRECATED=	nautilus will be updated to the 3.x version which is not compatible with 2.x
EXPIRATION_DATE=2014-04-10

LIB_DEPENDS=	libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique

INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USES=		gettext gmake pkgconfig
USE_GNOME=	nautilus2 intlhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-nautilus-extdir=${LOCALBASE}/lib/nautilus/extensions-2.0

PORTDOCS=	AUTHORS COPYING ChangeLog ChangeLog-2008 ChangeLog-2009 INSTALL \
		MAINTAINERS NEWS README TODO export-format-id io-provider-id \
		objects-hierarchy.odg

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror"|"|g' ${WRKSRC}/configure
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's| install-dist_pkgdocDATA||g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.else
	@${REINPLACE_CMD} -e 's|doc/@PACKAGE@-@VERSION@|doc/@PACKAGE@|g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/nautilus/extensions-2.0/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/nautilus-actions/*.so

.include <bsd.port.mk>
