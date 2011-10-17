# New ports collection makefile for:	libgtop2
# Date Created:			29 April 2002
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libgtop/Makefile,v 1.56 2010/05/02 00:04:47 marcus Exp $
#

PORTNAME=	libgtop
PORTVERSION=	2.28.3
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 top library

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_XORG=	xau
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 ltverhack intlhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_NET_IF_VAR_H
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		libgtop2

PKGMESSAGE=	${FILESDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} >= 800000 && ${OSVERSION} < 800019 ) || \
	${OSVERSION} < 700104
RUN_DEPENDS+=	lsof:${PORTSDIR}/sysutils/lsof
.endif

post-configure:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f

post-install:
	@${CHGRP} kmem ${PREFIX}/bin/libgtop_server2
	@${CHMOD} 2555 ${PREFIX}/bin/libgtop_server2
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
