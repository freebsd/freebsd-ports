# New ports collection makefile for:   dnrd
# Date created:        06 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		dnrd
PORTVERSION=		2.20.3
CATEGORIES=		dns
MASTER_SITES=		SF

MAINTAINER=		natanael.copa@gmail.com
COMMENT=		A proxy DNS daemon

USE_GMAKE=		yes
USE_RC_SUBR=		${PORTNAME}
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

MAN8=		dnrd.8
DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README
EXAMPLES=	README-cache README-cygwin README-master TODO \
		master.sample

OPTIONS=	TCP "Enable TCP support" off \
		MASTER "Enable master file support" on \
		DEBUG "Enable debugging" off \
		RANDOM "Enable random source port" off

USERS=		dnrd
GROUPS=		dnrd
DNRD_DIR?=	${ETCDIR}

SUB_FILES=	pkg-install
SUB_LIST+=	DNRD_DIR=${DNRD_DIR}

.include <bsd.port.pre.mk>

.if defined(WITH_TCP)
CONFIGURE_ARGS+=	--enable-tcp
.endif

.if !defined(WITH_MASTER)
CONFIGURE_ARGS+=	--disable-master
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_RANDOM)
CONFIGURE_ARGS+=	--enable-random-src
.endif

do-install:
	@${ECHO} "==>  Creating dnrd directory"
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${INSTALL_PROGRAM} ${WRKSRC}/src/dnrd ${PREFIX}/sbin/
	@${INSTALL_MAN} ${WRKSRC}/doc/dnrd.8 ${MAN8PREFIX}/man/man8/
	@${INSTALL_DATA} ${WRKSRC}/doc/master.sample ${ETCDIR}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/doc/,} ${EXAMPLESDIR}/
.endif

.include <bsd.port.post.mk>
