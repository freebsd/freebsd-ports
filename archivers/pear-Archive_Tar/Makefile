# Ports collection makefile for:  pear-Archive_Tar
# Date created:			  28 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Archive_Tar
PORTVERSION=	1.3.1
CATEGORIES=	archivers pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR tar file management class

USE_PHP=	yes
WANT_PHP_PEAR=	yes

CATEGORY=	Archive
FILES=		Tar.php
DOCS=		Archive_Tar.txt

post-extract:
	@${MV} ${WRKSRC}/Archive/* ${WRKSRC}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
