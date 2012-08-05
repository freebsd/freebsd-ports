# New ports collection makefile for:	Java
# Date Created:				27 January 2006
# Whom:					Simun Mikecin <numisemis@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	Java
PORTVERSION=	4.7
PORTREVISION=	3
CATEGORIES=	devel java perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Perl extension for accessing a JVM remotely or locally

USE_RC_SUBR=	javaserver
PERL_CONFIGURE=	YES
USE_JAVA=	yes
JAVA_VERSION=	1.5+

MAN3=		Java.3 JavaArray.3

post-patch:
	${RM} ${WRKSRC}/java_server_install.pl

post-install:
	${MKDIR} ${PREFIX}/share/p5-Java
	${INSTALL_DATA} ${WRKSRC}/JavaServer.jar ${PREFIX}/share/p5-Java

.include <bsd.port.mk>
