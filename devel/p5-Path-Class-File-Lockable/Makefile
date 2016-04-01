# Created by: Tatsuya Ueda <ml+freebsd@tatsuya.info>
# $FreeBSD$

PORTNAME=	Path-Class-File-Lockable
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KARMAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ml+freebsd@tatsuya.info
COMMENT=	Lock your files with Path::Class::File

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-NFSLock>0:devel/p5-File-NFSLock \
		p5-Path-Class>0:devel/p5-Path-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
