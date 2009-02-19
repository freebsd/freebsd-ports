# Ports collection makefile for:  pear-Net_FTP
# Date created:			  06 January 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_FTP
PORTVERSION=	1.3.7
CATEGORIES=	ftp www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR OO interface to the PHP FTP functions plus some additions

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

USE_PHP=	ftp

PORTSCOUT=	skipv:1.4.0a2,1.4.0a1
CATEGORY=	Net
FILES=		FTP.php FTP/Observer.php FTP/Socket.php
EXAMPLES=	extensions.ini index.php observer.php socket.php
_EXAMPLESDIR=	example

TESTS=		AllTests.php Net_FTPTest.php config.php.dist extensions.ini\
		testfile.dat

post-extract:
	@${MV} ${WRKSRC}/Net/* ${WRKSRC}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
