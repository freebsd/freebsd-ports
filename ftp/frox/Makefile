# New ports collection makefile for:	frox
# Date created:				11 June 2002
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	frox
PORTVERSION=	0.7.8
CATEGORIES=	ftp
MASTER_SITES= 	http://www.hollo.org/frox/download/ \
		http://frox.sourceforge.net/download/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sem@ciam.ru
COMMENT=	Transparent FTP proxy with caching support

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=	frox.1
MAN5=	frox.conf.5

DOCS=	FAQ SECURITY CREDITS ChangeLog

PKGMESSAGE=	${WRKDIR}/pkg-message

CONFIGURE_ARGS= --enable-configfile=${PREFIX}/etc/frox.conf

.if defined(WITH_IPFILTER)
CONFIGURE_ARGS+= --enable-ipfilter
.endif
.if defined(WITH_VIRUS_SCAN)
CONFIGURE_ARGS+= --enable-virus-scan
.endif
.if !defined(WITHOUT_HTTP_CACHE)
CONFIGURE_ARGS+= --enable-http-cache
.endif
.if !defined(WITHOUT_LOCAL_CACHE)
CONFIGURE_ARGS+= --enable-local-cache
.endif
.if !defined(WITHOUT_CCP)
CONFIGURE_ARGS+= --enable-ccp
.endif
.if defined(RUN_AS_ROOT)
CONFIGURE_ARGS+= --enable-run-as-root
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You can use the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITH_IPFILTER=yes	use ipfilter instead of ipfw;"
	@${ECHO} "	WITH_VIRUS_SCAN=yes	enable to run external virus scaner on each"
	@${ECHO} "				download (experimental);"
	@${ECHO} "	WITHOUT_HTTP_CACHE=yes	disable use of external cache;"
	@${ECHO} "	WITHOUT_LOCAL_CACHE=yes	disable use of local cache;"
	@${ECHO} "	WITHOUT_CCP=yes		disable ftp-proxy style command control programs;"
	@${ECHO} "	RUN_AS_ROOT=yes		allow frox running as root for using"
	@${ECHO} "				port number <1024 (not recomended)."
	@${ECHO} ""

pre-patch:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message >${PKGMESSAGE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/frox ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/src/frox.conf ${PREFIX}/etc/frox.conf.sample
	${INSTALL_MAN} ${WRKSRC}/doc/frox.man ${PREFIX}/man/man1/frox.1
	${INSTALL_MAN} ${WRKSRC}/doc/frox.conf.man ${PREFIX}/man/man5/frox.conf.5

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif
	@${STRIP_CMD} ${PREFIX}/sbin/frox
	@if [ ! -f ${PREFIX}/etc/rc.d/${PORTNAME}.sh ]; then \
		${ECHO_CMD} "Install ${PREFIX}/etc/rc.d/${PORTNAME}.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/${PORTNAME}.sh ${PREFIX}/etc/rc.d/${PORTNAME}.sh; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
