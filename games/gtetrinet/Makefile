# New ports collection makefile for:	gtetrinet
# Date created:				27 Feb 2000
# Whom:					Dan Papasian <bugg@bugg.strangled.net>
#
# $FreeBSD$

PORTNAME=	gtetrinet
PORTVERSION=	0.5.1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack gnomeprefix esound
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin

MAN6=		gtetrinet.6

post-patch:
	@${REINPLACE_CMD} \
		's|[(]prefix[)]/games|{bindir}|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
