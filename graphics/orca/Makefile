# Created by: jsellens
# $FreeBSD$

PORTNAME=	orca
PORTVERSION=	0.27
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.orcaware.com/orca/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for plotting arbitrary data from text files onto a Web server

BUILD_DEPENDS=	\
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-Math-Interpolate>=0:${PORTSDIR}/math/p5-Math-Interpolate \
		rrdtool>=0:${PORTSDIR}/databases/rrdtool

USES=		perl5
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-html-dir=${PREFIX}/www/data/orca

MAN1=		orca.1

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
