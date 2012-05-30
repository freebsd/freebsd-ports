# New ports collection makefile for:	libisofs
# Date created:		2008 November 06
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	libisofs
PORTVERSION=	1.1.2
CATEGORIES=	devel
MASTER_SITES=	http://files.libburnia-project.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libburnia ISO9660 filesystem creation library

LIB_DEPENDS=	burn.4:${PORTSDIR}/devel/libburn

GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/configure

.include <bsd.port.mk>
