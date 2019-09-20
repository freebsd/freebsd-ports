# Created by: Sergey Matveychuk <sem@ciam.ru>
# $FreeBSD$

PORTNAME=	frox
PORTVERSION=	0.7.18
PORTREVISION=	3
CATEGORIES=	ftp
MASTER_SITES=	http://www.hollo.org/frox/download/ \
		http://frox.sourceforge.net/download/ \
		SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transparent FTP proxy with caching support

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-configfile=${PREFIX}/etc/frox.conf

USE_RC_SUBR=	frox
SUB_FILES=	pkg-message

PORTDOCS=	SECURITY CREDITS ChangeLog FAQ.html FAQ-1.html FAQ-2.html \
		FAQ-3.html FAQ-4.html FAQ-5.html FAQ-6.html FAQ-7.html \
		FAQ-8.html
PORTEXAMPLES=	*
PLIST_FILES=	sbin/frox \
		man/man1/frox.1.gz \
		man/man5/frox.conf.5.gz

OPTIONS_DEFINE=	VIRUS_SCAN HTTP_CACHE LOCAL_CACHE CCP ROOT_RUN DOCS EXAMPLES
OPTIONS_DEFAULT=	HTTP_CACHE CCP

OPTIONS_RADIO=	PFILTER
OPTIONS_RADIO_PFILTER=	IPFILTER PF

IPFILTER_DESC=		Use ipfilter instead of ipfw
PF_DESC=		Build with pf(4) support
VIRUS_SCAN_DESC=	Run external virus scaner on each download
HTTP_CACHE_DESC=	Enable use of external cache
LOCAL_CACHE_DESC=	Enable use of local cache
CCP_DESC=		Ftp-proxy style command control programs
ROOT_RUN_DESC=		Allow frox running as root (not recomended)

IPFILTER_CONFIGURE_ENABLE=	ipfilter
PF_CPPFLAGS=			-DPF
VIRUS_SCAN_CONFIGURE_ENABLE=	virus-scan
HTTP_CACHE_CONFIGURE_ENABLE=	http-cache
LOCAL_CACHE_CONFIGURE_ENABLE=	local-cache
CCP_CONFIGURE_ENABLE=		ccp
ROOT_RUN_CONFIGURE_ENABLE=	run-as-root

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/frox ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/doc/frox.man ${STAGEDIR}${MANPREFIX}/man/man1/frox.1
	${INSTALL_MAN} ${WRKSRC}/doc/frox.conf.man ${STAGEDIR}${MANPREFIX}/man/man5/frox.conf.5

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/frox.conf ${STAGEDIR}${EXAMPLESDIR}/frox.conf

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
