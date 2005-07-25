# Ports collection makefile for:  zhcon
# Date created:                   Sun Sep 9, 2001
# Whom:                           statue@freebsd.sinica.edu.tw
#
# $FreeBSD$
#

PORTNAME=	zhcon
PORTVERSION=	0.2.3
PORTREVISION=	5
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast Console Chinese System which supports framebuffer device

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}
USE_GMAKE=	yes
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		zhcon.1

post-patch:
	@${REINPLACE_CMD} -Ee 's,/dev/vga,/dev/ttyv0,g' ${WRKSRC}/src/display/fbdev.cpp
	@${REINPLACE_CMD} -Ee 's,(\s*=\s*)("?)/usr/local([^"]*)("?),\1\2${PREFIX}\3\4,g' \
		-e '/_nl_expand_alias/s,\(0\),\(\),g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
