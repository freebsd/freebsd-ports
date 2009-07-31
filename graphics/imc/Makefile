# ex:ts=8
# New ports collection makefile for:	imc
# Date created:				Apr 30, 2002
# Whom:					Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	imc
PORTVERSION=	4.3
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://users.skynet.be/Peter.Verthez/projects/imc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image Compiler

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes

MAN1=		imc.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
