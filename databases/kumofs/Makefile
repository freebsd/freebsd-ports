# New ports collection makefile for:	msgpack
# Date created:		18 Jan 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kumofs
PORTVERSION=	0.3.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
DISTNAME=	kumofs-${GIT_REVISION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Scalabe and highly available distributed key-value store

LIB_DEPENDS=	msgpack:${PORTSDIR}/devel/msgpack \
		tokyocabinet:${PORTSDIR}/databases/tokyocabinet
RUN_DEPENDS=	rubygem-msgpack>0:${PORTSDIR}/devel/rubygem-msgpack

WRKSRC=		${WRKDIR}/etolabo-kumofs-${GIT_REVISION}
USE_AUTOTOOLS=	libtool:22 autoheader:262 autoconf:262 automake:110 aclocal:110
ACLOCAL_ARGS=	# empty
AUTOMAKE_ARGS=	--add-missing --copy
CONFIGURE_ARGS=	--with-msgpack=${LOCALBASE}
USE_GMAKE=	yes
USE_RUBY=	yes

GIT_REVISION=	2a0c402

MAN1=	kumoctl.1 \
	kumohash.1 \
	kumolog.1 \
	kumomergedb.1 \
	kumostat.1 \
	kumotop.1

pre-configure:
	cd ${WRKSRC}; ${TOUCH} README
	cd ${WRKSRC}; ${LIBTOOLIZE} --force --copy

.include <bsd.port.mk>
