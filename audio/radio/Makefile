# New ports collection makefile for:	radio
# Date created:		5 July 1995
# Whom:			janek@gaja.ipan.lublin.pl
#
# $FreeBSD$
#

PORTNAME=	radio
PORTVERSION=	2.0.4
CATEGORIES=	audio net
MASTER_SITES=	ftp://ftp.cwi.nl/pub/audio/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.Org

NO_WRKSUBDIR=	yes
MAKE_FLAGS=	FreeBSD -f
MAN1=		radio.1 broadcast.1

post-patch:
	@${SED} -e 's,machine/soundcard.h,sys/soundcard.h,' < \
		${WRKSRC}/radio.c > ${WRKSRC}/radio.c.new
	@${MV} ${WRKSRC}/radio.c.new ${WRKSRC}/radio.c

.include <bsd.port.mk>
