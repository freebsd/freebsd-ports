# Ports collection makefile for:  pear-Net_FTP
# Date created:			  06 January 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_FTP
PORTVERSION=	1.3.1
CATEGORIES=	ftp www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR OO interface to the PHP FTP functions plus some additions

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	ftp

CATEGORY=	Net
FILES=		FTP.php FTP/Observer.php
EXAMPLES=	extensions.ini index.php observer.php
_EXAMPLESDIR=	example

post-extract:
	@${MV} ${WRKSRC}/Net/* ${WRKSRC}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
