# Ports collection makefile for:  cadubi
# Date created:			  24 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cadubi
PORTVERSION=	1.2
CATEGORIES=	graphics editors
MASTER_SITES=	http://www.logicallemon.com/projects/cadubi/downloads/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ASCII drawing utility

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cadubi ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/CADUBI.pl ${PREFIX}/libexec
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cadubi
	${INSTALL_DATA} ${WRKSRC}/CADUBI.help ${PREFIX}/share/doc/cadubi
.endif

.include <bsd.port.mk>
