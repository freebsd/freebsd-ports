# New ports collection makefile for:	libgtop2
# Date Created:			29 April 2002
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgtop2
PORTVERSION=	2.10.1
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.10
DISTNAME=	libgtop-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 top library

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_BZIP2=	yes
USE_PERL5=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INFO=		libgtop2

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
PKGMESSAGE=	${FILESDIR}/pkg-message
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-sysdeps_freebsd_Makefile.in
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|int64_t|gint64|g' \
		${WRKSRC}/include/glibtop/command.h \
		${WRKSRC}/include/glibtop/proclist.h \
		${WRKSRC}/lib/lib.pl

post-install:
	@${CHGRP} kmem ${PREFIX}/bin/libgtop_server2
	@${CHMOD} 2555 ${PREFIX}/bin/libgtop_server2
.if ${OSVERSION} >= 600000
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
