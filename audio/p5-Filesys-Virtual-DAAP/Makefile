# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Filesys-Virtual-DAAP
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Present a DAAP share as a VFS

RUN_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Filesys-Virtual>=0:${PORTSDIR}/devel/p5-Filesys-Virtual \
		p5-Filesys-Virtual-Plain>=0:${PORTSDIR}/devel/p5-Filesys-Virtual-Plain \
		p5-Net-DAAP-Client>=0:${PORTSDIR}/audio/p5-Net-DAAP-Client
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
NO_STAGE=	yes
USE_PERL5=	modbuild

MAN3=		Filesys::Virtual::DAAP.3

.include <bsd.port.mk>
