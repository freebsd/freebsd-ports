# New ports collection makefile for:	POE-Component-Client-FTP
# Date created:	   17 March 2002
# Whom:		   Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-FTP
PORTVERSION=	0.14
CATEGORIES=	ftp perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Implements an FTP client POE Component

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	PERL_MM_USE_DEFAULT=yes

MAN3=		POE::Component::Client::FTP.3

post-patch:
	@${PERL} -pi -e '$$_="" if /^use warnings/; s/\x0d(?=\x0a)//;' \
		${WRKSRC}/FTP.pm

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
