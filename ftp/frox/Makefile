# Created by: Sergey Matveychuk <sem@ciam.ru>
# $FreeBSD$

PORTNAME=	frox
PORTVERSION=	0.7.18
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	http://www.hollo.org/frox/download/ \
		http://frox.sourceforge.net/download/ \
		SF

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Transparent FTP proxy with caching support

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

USE_RC_SUBR=	frox
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

OPTIONS_DEFINE=	IPFILTER PF VIRUS_SCAN HTTP_CACHE LOCAL_CACHE CCP ROOT_RUN
OPTIONS_DEFAULT=	HTTP_CACHE CCP

IPFILTER_DESC=		Use ipfilter instead of ipfw
PF_DESC=		Build with pf(4) support
VIRUS_SCAN_DESC=	Run external virus scaner on each download
HTTP_CACHE_DESC=	Enable use of external cache
LOCAL_CACHE_DESC=	Enable use of local cache
CCP_DESC=	 	Ftp-proxy style command control programs
ROOT_RUN_DESC=	 	Allow frox running as root (not recomended)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPFILTER}
CONFIGURE_ARGS+=	--enable-ipfilter
.endif

.if ${PORT_OPTIONS:MPF}
CPPFLAGS+=		-DPF
.endif

.if ${PORT_OPTIONS:MVIRUS_SCAN}
CONFIGURE_ARGS+=	--enable-virus-scan
.endif

.if ${PORT_OPTIONS:MHTTP_CACHE}
CONFIGURE_ARGS+=	--enable-http-cache
.endif

.if ${PORT_OPTIONS:MLOCAL_CACHE}
CONFIGURE_ARGS+=	--enable-local-cache
.endif

.if ${PORT_OPTIONS:MCCP}
CONFIGURE_ARGS+=	--enable-ccp
.endif

.if ${PORT_OPTIONS:MROOT_RUN}
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

.include <bsd.port.mk>
