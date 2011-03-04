# New ports collection makefile for:	homebank
# Date created:				24 June 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	homebank
PORTVERSION=	4.4
CATEGORIES=	finance
MASTER_SITES=	http://homebank.free.fr/public/

MAINTAINER=	c0rn@o2.pl
COMMENT=	Manage your personal accounts at home

LICENSE=	GPLv2
LICENSE_FILE_GPLv2=${WRKSRC}/COPYING

OPTIONS=	OFX "Enable libOFX support" on

USE_GNOME=	desktopfileutils gnomehier gtk20
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_ICONS=	yes

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_OFX)
CONFIGURE_ARGS+=--without-ofx
.else
LIB_DEPENDS+=	ofx.4:${PORTSDIR}/finance/libofx
CONFIGURE_ARGS+=--with-ofx
.endif

post-extract:
	@${CHMOD} ${BINMODE} ${WRKSRC}/install-sh

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@-update-desktop-database
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>
