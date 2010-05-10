# New ports collection makefile for:	nautilus-actions
# Date created:		2005-08-31
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/nautilus-actions/Makefile,v 1.21 2010/04/16 23:41:09 kwm Exp $
#

PORTNAME=	nautilus-actions
PORTVERSION=	2.30.2
CATEGORIES=	deskutils
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extension for Nautilus to configure programs to launch on files

LIB_DEPENDS=	uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique

INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	nautilus2 intlhack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-nautilus-extdir=${LOCALBASE}/lib/nautilus/extensions-2.0

PORTDOCS=	AUTHORS COPYING ChangeLog ChangeLog-2008 ChangeLog-2009 INSTALL \
		MAINTAINERS NEWS README TODO export-format-id io-provider-id \
		objects-hierarchy.odg

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-configure
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's| install-dist_pkgdocDATA||g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.else
	@${REINPLACE_CMD} -e 's|doc/@PACKAGE@-@VERSION@|doc/@PACKAGE@|g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.post.mk>
