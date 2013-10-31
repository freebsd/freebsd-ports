# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PV
PORTVERSION=	1.5
CATEGORIES=	devel net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	PerlVision-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl5 library for text-mode user interface widgets

RUN_DEPENDS=	p5-Curses>=0:${PORTSDIR}/devel/p5-Curses

USES=		perl5

NO_BUILD=	YES
PLIST_FILES=	%%SITE_PERL%%/PV.pm

do-install:
	${MKDIR} -m 755 ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/
	${INSTALL_DATA} ${WRKSRC}/PV.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/

.include <bsd.port.mk>
