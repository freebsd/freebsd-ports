# Ports collection makefile for:  pear-Archive_Tar
# Date created:			  28 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Archive_Tar
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	archivers www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR tar file management class

BUILD_DEPENDS=	pear:${PORTSDIR}/lang/php4
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Archive/Tar.php
DOCS=		Archive_Tar.txt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/php4/bsd.php.mk"
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
