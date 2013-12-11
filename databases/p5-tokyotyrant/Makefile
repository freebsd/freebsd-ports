# Created by: Hiroyuki Hanai <hanai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tokyotyrant
PORTVERSION=	1.16
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	http://fallabs.com/${PORTNAME}/perlpkg/
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-perl-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl5 interface to the TokyoTyrant

BUILD_DEPENDS=	tokyotyrant>=1.1.40:${PORTSDIR}/databases/tokyotyrant
LIB_DEPENDS=	libtokyotyrant.so:${PORTSDIR}/databases/tokyotyrant

USES=		perl5
USE_PERL5=	configure

MAN3=		TokyoTyrant.3

NO_STAGE=	yes
.include <bsd.port.mk>
