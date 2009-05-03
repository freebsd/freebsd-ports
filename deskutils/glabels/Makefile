# New ports collection makefile for:	glabels
# Date created:		29 September 2002
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#   $MCom: ports/deskutils/glabels/Makefile,v 1.7 2007/05/19 21:36:02 marcus Exp $
#

PORTNAME=	glabels
PORTVERSION=	2.2.5
CATEGORIES=	deskutils
MASTER_SITES=	SF

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A program to create labels and business cards

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget libgnomeui \
		desktopfileutils intlhack ltverhack
WANT_GNOME=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		glabels.1

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mevolutiondataserver}!=""
USE_GNOME+=		evolutiondataserver
CONFIGURE_ARGS+=	--with-libebook
.else
CONFIGURE_ARGS+=	--without-libebook
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|malloc\.h|stdlib\.h|g' \
		${WRKSRC}/iec16022-0.2.1/*.c

.include <bsd.port.post.mk>
