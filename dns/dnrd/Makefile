# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	dnrd
PORTVERSION=	2.20.3
CATEGORIES=	dns
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Proxy DNS daemon

LICENSE=	GPLv2

USES=		gmake
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README
PORTEXAMPLES=	README-cache README-cygwin README-master TODO master.sample

OPTIONS_DEFINE=	TCP MASTER DEBUG RANDOM DOCS EXAMPLES
OPTIONS_DEFAULT=MASTER
TCP_DESC=	TCP support
MASTER_DESC=	Master file support
RANDOM_DESC=	Random source port

USERS=		dnrd
GROUPS=		dnrd
DNRD_DIR?=	${ETCDIR}

SUB_FILES=	pkg-install
SUB_LIST+=	DNRD_DIR=${DNRD_DIR}

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
	@${SETENV} DESTDIR="${STAGEDIR}" PKG_PREFIX="${STAGEDIR}${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${INSTALL_PROGRAM} ${WRKSRC}/src/dnrd ${STAGEDIR}${PREFIX}/sbin/
	@${INSTALL_MAN} ${WRKSRC}/doc/dnrd.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/
	@${INSTALL_DATA} ${WRKSRC}/doc/master.sample ${STAGEDIR}${ETCDIR}/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
