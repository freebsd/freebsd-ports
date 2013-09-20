# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	libopendaap
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	devel audio net
MASTER_SITES=	http://crazney.net/programs/itunes/files/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	C lib used to connect to iTunes(R) music shares

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USES=		pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN3=		libopendaap.3

NO_STAGE=	yes
post-patch:
.for file in Makefile.in opendaap.pc.in
	@${REINPLACE_CMD} -e 's|-lpthread||g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
