# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Tcl
PORTVERSION=	1.04
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tcl extension module for Perl5

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PORTSCOUT=	limit:^[0-9\.]*$$

CONFIGURE_ARGS=	--nousestubs --tclsh ${TCLSH}
USES=		perl5 tcl
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Tcl/Tcl.so

.include <bsd.port.mk>
