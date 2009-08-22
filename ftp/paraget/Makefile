# ex:ts=8
# New ports collection makefile for:	paraget
# Date created:			Apr 18, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	paraget
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	ftp perl5
MASTER_SITES=	SF

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Parallel ftp-fetching program

BUILD_DEPENDS=	${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/${PERL_ARCH}/Class/MethodMaker.pm:${PORTSDIR}/devel/p5-Class-MethodMaker
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple

PERL_CONFIGURE=	yes

MAN1=	paraget.1

.include <bsd.port.mk>
