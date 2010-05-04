# New ports collection makefile for:	TokyoCabinet
# Date created:		03 May 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	TokyoCabinet
PORTVERSION=	1.33
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://1978th.net/tokyocabinet/perlpkg/
MASTER_SITE_SUBDIR=	kuriyama
PKGNAMEPREFIX=	p5-
DISTNAME=	tokyocabinet-perl-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for TokyoCabinet

LIB_DEPENDS=	tokyocabinet:${PORTSDIR}/databases/tokyocabinet

PERL_CONFIGURE=	yes

MAN3=	TokyoCabinet.3

.include <bsd.port.mk>
