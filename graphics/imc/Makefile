# ex:ts=8
# Ports collection makefile for:	imc
# Date created:			Apr 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	imc
PORTVERSION=	4.1
CATEGORIES=	graphics
MASTER_SITES=	http://users.skynet.be/Peter.Verthez/projects/imc/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Image Compiler

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm
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
