# New ports collection makefile for:   librep
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	librep
PORTVERSION=	0.13.6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm \
		intl.1:${PORTSDIR}/devel/gettext

PLIST_SUB=	GNUHOST=${ARCH}--freebsd${OSREL} VERSION=${PORTVERSION}

USE_NEWGCC=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lxpg4 -lintl"
CONFIGURE_ARGS=	--with-aclocaldir=${PREFIX}/share/aclocal

# Don't use USE_X_PREFIX - the port doesn't really require X11 to run.
# The reason why it should be in X11BASE is that sawfish (primary user of
# librep) installs shared object into one of the librep's directories, so
# they have to live in the same BASE to make PLISTs working.
# This looks like a little hack, because we have to tweak MTREE_FILE as well,
# thus partially duplicating bsd.port.mk, but what other choices do we have???
PREFIX?=	${X11BASE}

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 3
MTREE_FILE=	/etc/mtree/BSD.x11.dist
.else
MTREE_FILE=	/etc/mtree/BSD.x11-4.dist
.endif

.include <bsd.port.post.mk>
