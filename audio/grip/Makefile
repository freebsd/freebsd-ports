# New ports collection makefile for:	grip
# Date created:				31 May 2000
# Whom:					kbyanc@posi.net
#
# $FreeBSD$
#

PORTNAME=	grip
PORTVERSION=	3.1.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=grip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK front-end to external cd rippers and mp3 encoders

LIB_DEPENDS=	id3-3.8.2:${PORTSDIR}/audio/id3lib \
		ghttp.1:${PORTSDIR}/www/libghttp

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gnomevfs2 vte libgnomeui
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.if defined(WITH_CDPARANOIA)
LIB_DEPENDS+=	cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia
.else
CONFIGURE_ARGS+=	--disable-cdpar
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|helpdir)/images|helpdir)|g' ${WRKSRC}/doc/C/Makefile.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
