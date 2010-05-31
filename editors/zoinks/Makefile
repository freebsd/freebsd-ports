# New ports collection makefile for:	zoinks
# Date created:				26 July 2003
# Whom:					Mike Lockwood <mike@mikelockwood.com>
#
# $FreeBSD$
#

PORTNAME=	zoinks
PORTVERSION=	0.3.7
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	http://zoinks.mikelockwood.com/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	mike@mikelockwood.com
COMMENT=	An X11 programmer's editor and development environment

.if defined(WITH_IMLIB)
USE_GNOME=	imlib
CONFIGURE_ARGS+=	--enable-imlib
.else
CONFIGURE_ARGS+=	--disable-imlib
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

USE_XORG=	xpm
GNU_CONFIGURE=	yes

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Zoinks can be built with optional support for calculating image sizes"
	@${ECHO_MSG} "and image thumbnail creation for HTML files."
	@${ECHO_MSG} "These features require the Gnome imlib library."
	@${ECHO_MSG} "Use WITH_IMLIB=yes to enable these features."
	@${ECHO_MSG} ""

post-patch:
	@${FIND} ${WRKSRC} -name *.xpm | ${XARGS} ${REINPLACE_CMD} -e \
		's|^"|(char *)"|g'

.include <bsd.port.mk>
