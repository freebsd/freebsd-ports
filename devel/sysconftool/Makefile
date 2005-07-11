# New ports collection makefile for:	sysconftool
# Date created:				17 October 2001
# Whom:				Yarema <yds@CoolRat.org>
#
# $FreeBSD$
#

PORTNAME=	sysconftool
PORTVERSION=	0.14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Helps to install application configuration files

USE_BZIP2=		yes
USE_PERL5=		yes
USE_AUTOMAKE_VER=	15
USE_AUTOCONF_VER=	259

MAN1=		sysconftool.1 sysconftoolcheck.1
MAN7=		sysconftool.7

pre-patch:
	@${CP} ${TEMPLATES}/config.guess ${TEMPLATES}/config.sub ${WRKSRC}

.include <bsd.port.mk>
