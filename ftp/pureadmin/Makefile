# ex:ts=8
# Ports collection makefile for:	pureadmin
# Date created:			Mar 4, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pureadmin
PORTVERSION=	0.3
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	purify

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Management utility for the PureFTPd

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix libglade2
USE_FAM=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|-std=gnu99||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
