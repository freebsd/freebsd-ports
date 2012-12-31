# $FreeBSD$

PORTNAME=	homebank
PORTVERSION=	4.4
PORTREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	http://homebank.free.fr/public/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Manage your personal accounts at home

LICENSE=	GPLv2
LICENSE_FILE_GPLv2=${WRKSRC}/COPYING

USE_GNOME=	desktopfileutils gnomehier gtk20
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS_DEFINE=	OFX
OFX_DESC=	Enable libOFX support
OPTIONS_DEFAULT=OFX

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOFX}
LIB_DEPENDS+=	ofx.5:${PORTSDIR}/finance/libofx
CONFIGURE_ARGS+=--with-ofx
.else
CONFIGURE_ARGS+=--without-ofx
.endif

post-extract:
	@${CHMOD} ${BINMODE} ${WRKSRC}/install-sh

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@-update-desktop-database
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
