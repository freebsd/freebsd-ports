# New ports collection makefile for:  staticcharge
# Date created:        26 October 2001
# Whom:                Mahlon <mahlon@martini.nu>
#
# $FreeBSD$
#

PORTNAME=	staticcharge
PORTVERSION=	0.7.3
PORTREVISION=	3
CATEGORIES=	dns
MASTER_SITES=	http://www.staticcling.org/clients/
DISTNAME=	ChargeGTK-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK client for the StaticCling dynamic DNS service

BUILD_DEPENDS=	wget:${PORTSDIR}/ftp/wget

PLIST_FILES=	bin/staticcharge
WRKSRC=		${WRKDIR}/staticcharge
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.ifdef DEBUG
CONFIGURE_ARGS+=	--enable-debug
.endif

post-patch:
	@${REINPLACE_CMD} -E 's,\(int\)([[:graph:]]+) = ,\1 = (char *),' \
		${WRKSRC}/src/checkexe.c ${WRKSRC}/src/checkip.c \
		${WRKSRC}/src/getfields.c

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
