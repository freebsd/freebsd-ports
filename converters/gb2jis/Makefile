# New ports collection makefile for:        gb2jis
# Date created:     16 September 2000
# Whom:             Zhang Shu
#
# $FreeBSD$
#

PORTNAME=	gb2jis
PORTVERSION=	1.5
CATEGORIES=	converters chinese japanese
MASTER_SITES=	ftp://ftp.ifcss.org/pub/software/unix/convert/
DISTNAME=	${PORTNAME}

MAINTAINER=	jo-c@is.aist-nara.ac.jp

ALL_TARGET=

MAN1=	gb2jis.1

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%MAN1PREFIX%%|${MAN1PREFIX}|g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
