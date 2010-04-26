# ports collection makefile for:	perl interface to TokyoTyrant
# Date created:				17 February 2010
# Whom:					Hiroyuki Hanai <hanai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tokyotyrant
PORTVERSION=	1.16
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	http://1978th.net/tokyotyrant/perlpkg/
DISTNAME=	${PORTNAME}-perl-${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl5 interface to the TokyoTyrant

BUILD_DEPENDS=	tokyotyrant>=1.1.40:${PORTSDIR}/databases/tokyotyrant
LIB_DEPENDS=	tokyotyrant:${PORTSDIR}/databases/tokyotyrant

PERL_CONFIGURE=	yes

MAN3=		TokyoTyrant.3

.include <bsd.port.mk>
