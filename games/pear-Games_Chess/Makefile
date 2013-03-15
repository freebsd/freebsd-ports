# Created by: Mark Huizer <xaa+ports@timewasters.nl>
# $FreeBSD$

PORTNAME=	Games_Chess
PORTVERSION=	1.0.1
CATEGORIES=	games devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR methods for constructing and validating chess games in PGN

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
