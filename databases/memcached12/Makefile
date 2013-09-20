# Created by: Sean Chittenden <seanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	memcached
PORTVERSION=	1.2.8
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance distributed memory object cache system

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

CONFLICTS=	memcached-1.4*

LATEST_LINK=	memcached12

USE_RC_SUBR=	memcached
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=		--with-libevent=${LOCALBASE} --program-prefix=

PORTSCOUT=	ignore:1

OPTIONS_DEFINE=	REPCACHED SASL DOCS
REPCACHED_DESC=	Enable data replication feature

MAN1=		memcached.1

PLIST_FILES=	bin/memcached \
		bin/memcached-debug \
		bin/memcached-tool

PORTDOCS=	protocol.txt threads.txt

NO_STAGE=	yes
.include <bsd.port.pre.mk>

CFLAGS+=       -fstack-protector

.if ${PORT_OPTIONS:MREPCACHED}
# WWW: http://repcached.lab.klab.org/
PATCH_SITES+=		${MASTER_SITE_SOURCEFORGE:C/%SUBDIR%/repcached\/repcached\/2.2-${PORTVERSION}/}
PATCH_DIST_STRIP+=	-p1
PATCHFILES+=		repcached-2.2-${PORTVERSION}.patch.gz
CONFIGURE_ARGS+=	--enable-replication --disable-threads
.endif

.if ${PORT_OPTIONS:MSASL}
LIB_DEPENDS+=		sasl2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--enable-sasl
CFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-sasl
.endif

post-configure:
	@${REINPLACE_CMD} -e 's#doc/memcached.1##' ${WRKSRC}/Makefile

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/memcached-tool ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

test:
	${MAKE} -C ${WRKSRC} test

.include <bsd.port.post.mk>
