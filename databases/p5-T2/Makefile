# Created by: Scott McWhirter <scott@surreytech.co.uk>
# $FreeBSD$

PORTNAME=	T2
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SAMV
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object Relational mapping system

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Set-Object>=0:${PORTSDIR}/devel/p5-Set-Object \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Tangram>=0:${PORTSDIR}/databases/p5-Tangram \
		p5-Class-Tangram>=0:${PORTSDIR}/devel/p5-Class-Tangram
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e \
		'/eval/s|^|# | ; \
		 /deploy/s|^|#| ; \
		 /print/s|^|#| ; \
		 /NOTESTS/s|^|#|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
