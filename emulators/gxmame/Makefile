# New ports collection makefile for:	gxmame
# Date created:			04 Oct 2003
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	gxmame
PORTVERSION=	0.34b
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tlp@liquidx.org
COMMENT=	GXmame is a GTK frontend for xmame

RUN_DEPENDS=	xmame:${PORTSDIR}/emulators/xmame
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		intl.5:${PORTSDIR}/devel/gettext-old

USE_GZIP=	yes
USE_XLIB=	yes
USE_GNOME=	gtk20
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386

DOCDIR=		share/doc/${PORTNAME}
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-xmame-dir=${X11BASE}/share/xmame

post-configure:
	@${REINPLACE_CMD} -e 's|$$(top_builddir)/./mkinstalldirs|./mkinstalldirs|' ${WRKSRC}/intl/Makefile

.include <bsd.port.mk>
