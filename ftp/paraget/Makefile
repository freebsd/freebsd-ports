# ex:ts=8
# New ports collection makefile for:	paraget
# Date created:			Apr 18, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	paraget
PORTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	ftp perl5
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallel ftp-fetching program

BUILD_DEPENDS=	p5-Class-MethodMaker>=0:${PORTSDIR}/devel/p5-Class-MethodMaker
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple

PERL_CONFIGURE=	yes

MAN1=	paraget.1

.include <bsd.port.mk>
