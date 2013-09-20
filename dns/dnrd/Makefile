# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=		dnrd
PORTVERSION=		2.20.3
CATEGORIES=		dns
MASTER_SITES=		SF

MAINTAINER=		natanael.copa@gmail.com
COMMENT=		A proxy DNS daemon

USE_GMAKE=		yes
USE_RC_SUBR=		${PORTNAME}
GNU_CONFIGURE=		yes

MAN8=		dnrd.8
DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README
EXAMPLES=	README-cache README-cygwin README-master TODO \
		master.sample

OPTIONS_DEFINE=	TCP MASTER DEBUG RANDOM DOCS
OPTIONS_DEFAULT= MASTER
TCP_DESC=	TCP support
MASTER_DESC=	Master file support
RANDOM_DESC=	Random source port

USERS=		dnrd
GROUPS=		dnrd
DNRD_DIR?=	${ETCDIR}

SUB_FILES=	pkg-install
SUB_LIST+=	DNRD_DIR=${DNRD_DIR}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCP}
CONFIGURE_ARGS+=	--enable-tcp
.endif

.if ${PORT_OPTIONS:MMASTER}
CONFIGURE_ARGS+=	--disable-master
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MRANDOM}
CONFIGURE_ARGS+=	--enable-random-src
.endif

do-install:
	@${ECHO} "==>  Creating dnrd directory"
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${INSTALL_PROGRAM} ${WRKSRC}/src/dnrd ${PREFIX}/sbin/
	@${INSTALL_MAN} ${WRKSRC}/doc/dnrd.8 ${MAN8PREFIX}/man/man8/
	@${INSTALL_DATA} ${WRKSRC}/doc/master.sample ${ETCDIR}/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/doc/,} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
