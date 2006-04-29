# ex:ts=8
# Ports collection makefile for:	imc
# Date created:			Apr 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	imc
PORTVERSION=	4.3
CATEGORIES=	graphics
MASTER_SITES=	http://users.skynet.be/Peter.Verthez/projects/imc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image Compiler

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	imc.1

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
