# New ports collection makefile for:	sysconftool
# Date created:				17 October 2001
# Whom:				Yarema <yds@CoolRat.org>
#
# $FreeBSD$
#

PORTNAME=	sysconftool
PORTVERSION=	0.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	yds@CoolRat.org

USE_PERL5=	yes
USE_AUTOMAKE_VER=	14

MAN1=		sysconftool.1 sysconftoolcheck.1
MAN7=		sysconftool.7

pre-patch:
	@${PERL} -pi.orig -e 's|autoconf|${AUTOCONF}|; \
		s|autoheader|${AUTOHEADER}|; s|aclocal|${ACLOCAL}|; \
		s|automake|${AUTOMAKE}|' ${WRKSRC}/configure

.include <bsd.port.mk>
