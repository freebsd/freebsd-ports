# New ports collection makefile for:	frox
# Date created:				11 June 2002
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	frox
PORTVERSION=	0.7.18
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	http://www.hollo.org/frox/download/ \
		http://frox.sourceforge.net/download/ \

		SF		


MAINTAINER=	sem@FreeBSD.org
COMMENT=	Transparent FTP proxy with caching support

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

USE_RC_SUBR=	frox.sh
SUB_FILES=	pkg-message

MAN1=		frox.1
MAN5=		frox.conf.5

PORTDOCS=	SECURITY CREDITS ChangeLog FAQ.html FAQ-1.html FAQ-2.html \
		FAQ-3.html FAQ-4.html FAQ-5.html FAQ-6.html FAQ-7.html \
		FAQ-8.html
PLIST_FILES=	sbin/frox ${EXAMPLESDIR:S,${PREFIX}/,,}/frox.conf
PLIST_DIRS=	${EXAMPLESDIR:S,${PREFIX}/,,}

PKGMESSAGE=	${WRKDIR}/pkg-message

CONFIGURE_ARGS=	--enable-configfile=${PREFIX}/etc/frox.conf

OPTIONS=	IPFILTER "Use ipfilter instead of ipfw" off \
		PF "Build with pf(4) support" off \
		VIRUS_SCAN "Run external virus scaner on each download" off \
		HTTP_CACHE "Enable use of external cache" on \
		LOCAL_CACHE "Enable use of local cache" off \
		CCP "Ftp-proxy style command control programs" on \
		ROOT_RUN "Allow frox running as root (not recomended)" off
.include <bsd.port.pre.mk>

# Set default options
.if !defined(WITHOUT_HTTP_CACHE)
WITH_HTTP_CACHE=	yes
.endif
.if !defined(WITHOUT_CCP)
WITH_CCP=	yes
.endif

.if defined(WITH_IPFILTER)
CONFIGURE_ARGS+=	--enable-ipfilter
.endif
.if defined(WITH_PF)
CONFIGURE_ENV+=		"CPPFLAGS=-DPF"
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/frox ${PREFIX}/sbin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/frox.conf ${EXAMPLESDIR}/frox.conf
	${INSTALL_MAN} ${WRKSRC}/doc/frox.man ${MANPREFIX}/man/man1/frox.1
	${INSTALL_MAN} ${WRKSRC}/doc/frox.conf.man ${MANPREFIX}/man/man5/frox.conf.5

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif
	@${STRIP_CMD} ${PREFIX}/sbin/frox; \
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
