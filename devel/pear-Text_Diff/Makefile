# Created by: Joseph Scott <joseph@randomnetworks.com>
# $FreeBSD$

PORTNAME=	Text_Diff
PORTVERSION=	1.1.1
CATEGORIES=	devel pear

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	Engine for performing and rendering text diffs

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

PEAR_AUTOINSTALL=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
