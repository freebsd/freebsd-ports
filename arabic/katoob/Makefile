# New ports collection makefile for:	katoob
# Date created:				13th September 2003
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	katoob
PORTVERSION=	0.3.5
PORTREVISION=	4
CATEGORIES=	arabic
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	arabeyes

MAINTAINER=	samy@kerneled.org
COMMENT=	Light-weight, bidirectional editor for arabic texts

MAN1=		katoob.1

USE_GMAKE=		yes
USE_X_PREFIX=		yes
USE_GNOME=		gnomeprefix gnomehack gtk20
USE_INC_LIBTOOL_VER=	13
USE_GETOPT_LONG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(WITH_HIGHLIGHTING) || exists(${X11BASE}/libdata/pkgconfig/gtksourceview-1.0.pc)
CONFIGURE_ARGS+=	"--enable-highlight"
USE_GNOME+=		gtksourceview
.endif

.if defined(WITH_SPELLCHECKER) || exists(${LOCALBASE}/lib/libaspell.so.16)
CONFIGURE_ARGS+=	"--enable-spell"
LIB_DEPENDS+=		aspell.16:${PORTSDIR}/textproc/aspell
.endif

.include <bsd.port.post.mk>
