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

LIB_DEPENDS=	uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique

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

NO_STAGE=	yes
post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's| install-dist_pkgdocDATA||g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.else
	@${REINPLACE_CMD} -e 's|doc/@PACKAGE@-@VERSION@|doc/@PACKAGE@|g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
