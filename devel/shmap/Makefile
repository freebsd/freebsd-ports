# ex:ts=8
# Ports collection makefile for:	shmap
# Date Created:			Feb 20, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	shmap
PORTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	mm:${PORTSDIR}/devel/mm

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
CONIFGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

pre-configure:
	@${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}

.include <bsd.port.mk>
