# New ports collection makefile for:	frox
# Date created:				11 June 2002
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	frox
PORTVERSION=	0.7.12
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	http://www.hollo.org/frox/download/ \
		http://frox.sourceforge.net/download/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sem@ciam.ru
COMMENT=	Transparent FTP proxy with caching support

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

USE_RC_SUBR=	yes
RC_DIR?=	${PREFIX}/etc/rc.d
RC_SUFX?=	.sh
SED_SCRIPT=	-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%RC_SUBR%%|${RC_SUBR}|g' \
		-e 's|%%RC_DIR%%|${RC_DIR}|g' \
		-e 's|%%RC_SUFX%%|${RC_SUFX}|g'

PLIST_SUB+=	RC_DIR=${RC_DIR} RC_SUFX=${RC_SUFX}

MAN1=	frox.1
MAN5=	frox.conf.5

PORTDOCS=	FAQ SECURITY CREDITS ChangeLog
PLIST_FILES=	sbin/frox etc/frox.conf.sample etc/rc.d/frox.sh

PKGMESSAGE=	${WRKDIR}/pkg-message

CONFIGURE_ARGS=	--enable-configfile=${PREFIX}/etc/frox.conf

OPTIONS=	IPFILTER "Use ipfilter instead of ipfw" off \
		VIRUS_SCAN "Run external virus scaner on each download" off \
		HTTP_CACHE "Enable use of external cache" on \
		LOCAL_CACHE "Enable use of local cache" off \
		CCP "Ftp-proxy style command control programs" on \
		ROOT_RUN "Allow frox running as root (not recomended)" off

.include <bsd.port.pre.mk>

.if defined(WITH_IPFILTER)
CONFIGURE_ARGS+=	--enable-ipfilter
.endif
.if defined(WITH_VIRUS_SCAN)
CONFIGURE_ARGS+=	--enable-virus-scan
.endif
.if defined(WITH_HTTP_CACHE)
CONFIGURE_ARGS+=	--enable-http-cache
.endif
.if defined(WITH_LOCAL_CACHE)
CONFIGURE_ARGS+=	--enable-local-cache
.endif
.if defined(WITH_CCP)
CONFIGURE_ARGS+=	--enable-ccp
.endif
.if defined(WITH_ROOT_RUN)
CONFIGURE_ARGS+=	--enable-run-as-root
.endif

pre-patch:
	@${SED} ${SED_SCRIPT} ${PKGDIR}/pkg-message >${PKGMESSAGE}
	@${SED} ${SED_SCRIPT} ${FILESDIR}/frox.sh > ${WRKDIR}/frox.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/frox ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/src/frox.conf ${PREFIX}/etc/frox.conf.sample
	${INSTALL_MAN} ${WRKSRC}/doc/frox.man ${PREFIX}/man/man1/frox.1
	${INSTALL_MAN} ${WRKSRC}/doc/frox.conf.man ${PREFIX}/man/man5/frox.conf.5

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif
	@${STRIP_CMD} ${PREFIX}/sbin/frox; \
	${ECHO_MSG} "Install ${RC_DIR}/frox${RC_SUFX} startup file."; \
	${INSTALL_SCRIPT} -m 751 ${WRKDIR}/frox.sh ${RC_DIR}/frox${RC_SUFX}; \
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
