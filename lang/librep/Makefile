# New ports collection makefile for:   librep
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	librep
PORTVERSION=	0.16.1
PORTREVISION=	1
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	librep
#MASTER_SITES=	${MASTER_SITE_GNOME}
#MASTER_SITE_SUBDIR=	stable/sources/librep
#DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm \
		intl.4:${PORTSDIR}/devel/gettext

PLIST_SUB=	GNUHOST=${ARCH}-pc-freebsd${OSREL:C/\..*//} VERSION=${PORTVERSION}

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lxpg4 -lintl ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-aclocaldir=${PREFIX}/share/aclocal
CONFIGURE_TARGET=	${ARCH}-pc-freebsd${OSREL:C/\..*//}

# Don't use USE_X_PREFIX - the port doesn't really require X11 to run.
# The reason why it should be in X11BASE is that sawfish (primary user of
# librep) installs shared object into one of the librep's directories, so
# they have to live in the same BASE to make PLISTs working.
# This looks like a little hack, because we have to tweak MTREE_FILE as well,
# thus partially duplicating bsd.port.mk, but what other choices do we have???
PREFIX?=	${X11BASE}

.include <bsd.port.pre.mk>
.if ${OSVERSION} > 500023
LIB_DEPENDS+=	gmp.3:${PORTSDIR}/math/libgmp-freebsd
.endif

.if ${XFREE86_VERSION} == 3
MTREE_FILE=	/etc/mtree/BSD.x11.dist
.else
MTREE_FILE=	/etc/mtree/BSD.x11-4.dist
.endif

post-extract:
	@${RM} ${WRKSRC}/test

.include <bsd.port.post.mk>
