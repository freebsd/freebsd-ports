# Created by: Simun Mikecin <numisemis@yahoo.com>
# $FreeBSD$

PORTNAME=	Java
PORTVERSION=	4.7
PORTREVISION=	5
CATEGORIES=	devel java perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Perl extension for accessing a JVM remotely or locally

USE_RC_SUBR=	javaserver
USES=		perl5
USE_PERL5=	configure
USE_JAVA=	yes

post-patch:
	${RM} ${WRKSRC}/java_server_install.pl

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/p5-Java
	${INSTALL_DATA} ${WRKSRC}/JavaServer.jar ${STAGEDIR}${PREFIX}/share/p5-Java

.include <bsd.port.mk>
