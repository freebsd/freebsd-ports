# Ports collection makefile for:  pear-Console_Getopt
# Date created:			  23 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Console_Getopt
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR command-line option parser

BUILD_DEPENDS=	pear:${PORTSDIR}/lang/php4
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

do-install:
	@${MKDIR} ${PEARDIR}/Console
	@${CP} -Rp ${WRKSRC}/Console/Getopt.php ${PEARDIR}/Console
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Console

.include <bsd.port.post.mk>
