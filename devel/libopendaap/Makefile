# New ports collection makefile for:	libopendaap
# Date created:		2004-03-10
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	libopendaap
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	http://crazney.net/programs/itunes/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C lib used to connect to iTunes(R) music shares

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN3=		libopendaap.3

post-patch:
.for file in Makefile.in opendaap.pc.in
	@${REINPLACE_CMD} -e 's|-lpthread||g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
