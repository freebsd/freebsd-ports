# Ports collection makefile for:  zhcon
# Date created:                   Sun Sep 9, 2001
# Whom:                           statue@freebsd.sinica.edu.tw
#
# $FreeBSD$
#

PORTNAME=	zhcon
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast Console Chinese System which supports framebuffer device

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-included-gettext=${LOCALBASE}
USE_GMAKE=	yes
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386

MAN1=		zhcon.1

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/configure

.include <bsd.port.mk>
