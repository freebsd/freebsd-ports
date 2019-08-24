# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chef-provisioning
PORTVERSION=	2.7.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for creating machines and infrastructures idempotently in Chef

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cheffish>=4.0<15.0:devel/rubygem-cheffish \
		rubygem-inifile>=2.0.2:textproc/rubygem-inifile \
		rubygem-mixlib-install>=1.0:devel/rubygem-mixlib-install \
		rubygem-net-scp>=1.0<2:security/rubygem-net-scp \
		rubygem-net-ssh4>=2.9,2<5.0,2:security/rubygem-net-ssh4 \
		rubygem-net-ssh-gateway>=1.2<3.0:security/rubygem-net-ssh-gateway \
		rubygem-winrm>=2.0<3:sysutils/rubygem-winrm \
		rubygem-winrm-elevated>=1.0<2:sysutils/rubygem-winrm-elevated \
		rubygem-winrm-fs>=1.0<2:sysutils/rubygem-winrm-fs

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
