# New ports collection makefile for:	uclient
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	uclient
PORTVERSION=	0.10.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.ecs.soton.ac.uk/pub/worldforge/clients/uclient/ \
		ftp://ftp.ecs.soton.ac.uk/pub/worldforge/acorn/0.3/media/ \
		http://65.100.132.89/wf/downloads/clients/uclient/ \
		http://65.100.132.89/wf/downloads/acorn/0.3/media/ \
		ftp://two.woovis.com/pub/worldforge/clients/uclient/ \
		ftp://two.woovis.com/pub/worldforge/acorn/0.3/media/ \
		http://dreadnought.res.cmu.edu/worldforge/clients/uclient/ \
		http://dreadnought.res.cmu.edu/worldforge/acorn/0.3/media/
DISTFILES=	uclient-graphics-0.9.2.tar.gz \
		uclient-sound-0.9.2.tar.gz \
		${PORTNAME}-${PORTVERSION}-2.tar.gz

MAINTAINER=	lehmann@ans-netz.de

LIB_DEPENDS=	uta:${PORTSDIR}/devel/libuta \
		sigc.1:${PORTSDIR}/devel/libsigc++ \
		xml:${PORTSDIR}/textproc/libxml \
		Atlas.0:${PORTSDIR}/devel/atlas \
		varconf.0:${PORTSDIR}/devel/varconf
RUN_DEPENDS=	${LOCALBASE}/share/forge/media:${PORTSDIR}/games/acorn-media

USE_LIBTOOL=	YES
USE_AUTOMAKE=	YES
USE_GMAKE=	YES
USE_NEWGCC=	YES
WRKSRC=          ${WRKDIR}/uclient-0.10.0

CONFIGURE_ARGS=	--prefix=${PREFIX} --exec-prefix=${PREFIX}

CONFIGURE_SCRIPT=	autogen.sh

post-install:
	${MKDIR} ${PREFIX}/share/forge
	${CP} -r ${WRKDIR}/share/forge/* ${PREFIX}/share/forge

.include <bsd.port.mk>
