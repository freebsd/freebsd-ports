# New ports collection makefile for:	varconf
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	varconf
PORTVERSION=	0.3.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ecs.soton.ac.uk/pub/worldforge/libs/varconf/ \
		ftp://two.woovis.com/pub/worldforge/libs/varconf/ \
		http://dreadnought.res.cmu.edu/worldforge/libs/varconf/ \
		http://kafka.i-site.com/~novalis/mirrors/acorn/0.3/src/ \
		http://65.100.132.89/wf/downloads/libs/varconf/

MAINTAINER=	lehmann@ans-netz.de

LIB_DEPENDS=	sigc.1:${PORTSDIR}/devel/libsigc++ \
		Atlas.0:${PORTSDIR}/devel/atlas

USE_LIBTOOL=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX}

.include <bsd.port.mk>
