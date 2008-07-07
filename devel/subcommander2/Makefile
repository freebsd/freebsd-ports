# New ports collection makefile for:	subcommander
# Date created:		22 July 2007
# Whom:			sutra
#
# $FreeBSD$
#

PORTNAME=	subcommander
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://subcommander.tigris.org/files/documents/1759/35437/
DISTNAME=	Subcommander-${PORTVERSION}

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	Qt based multiplatform subversion client, diff & merge tool

LIB_DEPENDS=	neon.26:${PORTSDIR}/www/neon26 \
		apr-1.3:${PORTSDIR}/devel/apr-svn \
		boost_thread.4:${PORTSDIR}/devel/boost \
		svn_client-1.0:${PORTSDIR}/devel/subversion

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
CONFIGURE_ARGS+=	--with-boost=${LOCALBASE}
CONFIGURE_ARGS+=	--with-neon=${LOCALBASE}
CONFIGURE_ENV=	QTDIR=${LOCALBASE} CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.mk>
