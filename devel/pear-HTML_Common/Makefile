# Ports collection makefile for:  pear-HTML_Common
# Date created:			  29 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Common
PORTVERSION=	1.2.1
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR::HTML_Common is a base class for other HTML classes

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

do-install:
	@${MKDIR} ${PEARDIR}/HTML
	@${CP} -Rp ${WRKSRC}/Common.php ${PEARDIR}/HTML
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/HTML

.include <bsd.port.post.mk>
