# New ports collection makefile for:	memcached
# Date created:		July 21, 2003
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	memcached
PORTVERSION=	1.2.8
CATEGORIES=	databases
MASTER_SITES=	http://www.danga.com/memcached/dist/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	High-performance distributed memory object cache system

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

USE_RC_SUBR=	memcached
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=		--with-libevent=${LOCALBASE} --program-prefix=

OPTIONS=	REPCACHED	"Enable data replication feature"	off

MAN1=		memcached.1

PLIST_FILES=	bin/memcached \
		bin/memcached-debug \
		bin/memcached-tool

PORTDOCS=	memory_management.txt protocol.txt

.include <bsd.port.pre.mk>

.if defined(WITH_REPCACHED)
# WWW: http://repcached.lab.klab.org/
PATCH_SITES+=		${MASTER_SITE_SOURCEFORGE}
PATCH_SITE_SUBDIR=	repcached
PATCH_DIST_STRIP+=	-p1
PATCHFILES+=		repcached-2.2-${PORTVERSION}.patch.gz
CONFIGURE_ARGS+=	--enable-replication --disable-threads
.else
CONFIGURE_ARGS+=	--enable-threads
.endif

post-patch:
	${REINPLACE_CMD} -E -e 's!=(= "xyes")!\1!' ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's#doc/memcached.1##' ${WRKSRC}/Makefile

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/memcached-tool ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

test:
	${MAKE} -C ${WRKSRC} test

.include <bsd.port.post.mk>
