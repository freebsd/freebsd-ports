# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	paraget
PORTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	ftp perl5
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallel ftp-fetching program

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Class-MethodMaker>=0:devel/p5-Class-MethodMaker
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		p5-URI>=0:net/p5-URI \
		p5-XML-Simple>=0:textproc/p5-XML-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
