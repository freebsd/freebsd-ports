# Created by: Hiroyuki Hanai <hanai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tokyotyrant
PORTVERSION=	1.16
PORTREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	http://fallabs.com/${PORTNAME}/perlpkg/
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-perl-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl5 interface to the TokyoTyrant

BUILD_DEPENDS=	tokyotyrant>=1.1.40:databases/tokyotyrant
LIB_DEPENDS=	libtokyotyrant.so:databases/tokyotyrant

USES=		perl5 shebangfix
SHEBANG_FILES=	tcrtest.pl ttutest.pl
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
