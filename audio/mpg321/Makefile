# ex:ts=8
# New ports collection makefile for:	mpg321
# Date created:			Mar 17, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpg321
PORTVERSION=	0.1.2
CATEGORIES=	audio
MASTER_SITES=	http://www.linuxberg.com/files/ \
		http://gemini.woot.net/~hosehead/packages/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	ao.1:${PORTSDIR}/audio/libao \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
BUILD_DEPENDS=	${LOCALBASE}/lib/libmad.a:${PORTSDIR}/audio/mad

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lgnugetopt" \
		CFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}"
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		mpg321.1

.include <bsd.port.mk>
