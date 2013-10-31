# Created by: Rod Taylor <ports@rbt.ca>
# $FreeBSD$

PORTNAME=	Test-File-Contents
PORTVERSION=	0.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test routines for examining the contents of files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Text-Diff>=0.35:${PORTSDIR}/textproc/p5-Text-Diff
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
