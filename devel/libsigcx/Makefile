# ex:ts=8
# Ports collection makefile for:	libsigcx
# Date created:			Apr 6, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libsigcx
PORTVERSION=	0.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libsigcx

MAINTAINER=	ports@FreeBSD.org
COMMENT=	libSigC++ Extras

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12

USE_REINPLACE=	yes
USE_GNOME=	gtk20 gnomehack
USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,-pthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.include <bsd.port.mk>
