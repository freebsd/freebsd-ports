# New ports collection makefile for:	subcommander
# Date created:		22 July 2007
# Whom:			sutra
#
# $FreeBSD$
#

PORTNAME=	subcommander
PORTVERSION=	1.2.3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://subcommander.tigris.org/files/documents/1759/42385/
DISTNAME=	Subcommander-${PORTVERSION}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Qt based multiplatform subversion client, diff & merge tool

LIB_DEPENDS=	neon.28:${PORTSDIR}/www/neon28 \
		boost_thread.4:${PORTSDIR}/devel/boost-libs \
		svn_client-1.0:${PORTSDIR}/devel/subversion

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
CONFIGURE_ARGS+=--with-boost=${LOCALBASE} --with-neon=${LOCALBASE} \
		--with-subversion=${LOCALBASE}
CONFIGURE_ENV=	QTDIR=${LOCALBASE} CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

NO_LATEST_LINK=	yes

.include <bsd.port.mk>
