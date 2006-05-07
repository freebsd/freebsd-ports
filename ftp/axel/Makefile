# ex:ts=8
# New ports collection makefile for:	axel
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	axel
PORTVERSION=	1.0b
PORTREVISION=	0
CATEGORIES=	ftp
MASTER_SITES=	http://wilmer.gaast.net/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A download accelerator

USE_GETTEXT=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${PREFIX}/man --i18n=1

MAN1=		axel.1

post-configure:
	@${REINPLACE_CMD} -e 's,-O3,${CFLAGS},; s|gcc|${CC}|; \
		s|-pthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile.settings

.include <bsd.port.mk>
