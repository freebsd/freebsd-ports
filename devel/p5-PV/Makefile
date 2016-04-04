# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PV
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	devel net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	PerlVision-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl5 library for text-mode user interface widgets

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Curses>=0:devel/p5-Curses

USES=		perl5

NO_BUILD=	yes
PLIST_FILES=	%%SITE_PERL%%/PV.pm

do-install:
	${MKDIR} -m 755 ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/
	${INSTALL_DATA} ${WRKSRC}/PV.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/

.include <bsd.port.mk>
