# New ports collection makefile for:	gxmame
# Date created:			04 Oct 2003
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	gxmame
PORTVERSION=	0.35
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}beta1

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	GXmame is a GTK frontend for xmame

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	xmame:${PORTSDIR}/emulators/xmame

USE_GETTEXT=	yes
USE_GZIP=	yes
USE_ICONV=	yes
USE_XLIB=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_REINPLACE=	yes
#ONLY_FOR_ARCHS=	i386

GNU_CONFIGURE=	yes

CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-xmame-dir=${X11BASE}/share/xmame

post-configure:
	@${REINPLACE_CMD} -e 's|$$(top_builddir)/./mkinstalldirs|./mkinstalldirs|' ${WRKSRC}/intl/Makefile

.include <bsd.port.mk>
