# ex:ts=8
# Ports collection makefile for:	pureadmin
# Date created:			Mar 4, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pureadmin
PORTVERSION=	0.2.2
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	purify

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Management utility for the PureFTPd

LIB_DEPENDS=	fam.0:${PORTSDIR}/devel/fam

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gtk20
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e '/-g -Wall/d' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
