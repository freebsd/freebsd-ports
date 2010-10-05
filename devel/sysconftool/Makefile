# New ports collection makefile for:	sysconftool
# Date created:				17 October 2001
# Whom:				Yarema <yds@CoolRat.org>
#
# $FreeBSD$
#

PORTNAME=	sysconftool
PORTVERSION=	0.15
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/courier/${PORTNAME}/${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Helps to install application configuration files

USE_BZIP2=	yes
USE_PERL5=	yes
HAS_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

USE_AUTOTOOLS=	automake:111 aclocal:111 autoconf:267

MAN1=	sysconftool.1 sysconftoolcheck.1
MAN7=	sysconftool.7

pre-patch:
	@${CP} ${TEMPLATES}/config.guess ${TEMPLATES}/config.sub ${WRKSRC}

.include <bsd.port.mk>
