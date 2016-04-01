# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	File-Find-Rule-Filesys-Virtual
PORTVERSION=	1.22
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	File::Find::Rule adapted to Filesys::Virtual

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-Find-Rule>=0:devel/p5-File-Find-Rule \
		p5-Filesys-Virtual>=0:devel/p5-Filesys-Virtual \
		p5-Filesys-Virtual-Plain>=0:devel/p5-Filesys-Virtual-Plain
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
