# ex:ts=8
# Ports collection makefile for:	gnump3d
# Date created:			May 27, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnump3d
PORTVERSION=	0.9.9.7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	freebsd

MAN1=	mp3d.1 mp3d.conf.1 mp3d-top.1

post-patch:
	@${PERL} -pi -e "s,^PREFIX,#PREFIX,g ; \
		s,/usr/local,${PREFIX},g ; \
		s,-pthread,${PTHREAD_LIBS},g" ${WRKSRC}/mkfiles/freebsd

.include <bsd.port.mk>
