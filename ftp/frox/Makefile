# New ports collection makefile for:	frox
# Date created:				11 June 2002
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	frox
PORTVERSION=	0.7.4
CATEGORIES=	ftp
MASTER_SITES= 	http://www.hollo.org/frox/download/ \
		http://frox.sourceforge.net/download/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sem@ciam.ru

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=	frox.1
MAN5=	frox.conf.5

DOCS=	FAQ SECURITY CREDITS ChangeLog

PKGMESSAGE=	${WRKDIR}/pkg-message

CONFIGURE_ARGS= --enable-configfile=${PREFIX}/etc/frox.conf

.if defined(WITH_HTTP_CACHE)
CONFIGURE_ARGS+= --enable-http-cache
.endif
.if defined(WITH_IPFILTER)
CONFIGURE_ARGS+= --enable-ipfilter
.endif
.if defined(WITH_CCP)
CONFIGURE_ARGS+= --enable-ccp
.endif
.if defined(RUN_AS_ROOT)
CONFIGURE_ARGS+= --enable-run-as-root
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You can use the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITH_HTTP_CACHE=yes	enable http-cache (like squid) using;"
	@${ECHO} "	WITH_IPFILTER=yes	force use ipfilter instead of ipfw;"
	@${ECHO} "	WITH_CCP=yes		enable ftp-proxy style command control programs;"
	@${ECHO} "	RUN_AS_ROOT=yes		allow frox running as root (not recomended)"
	@${ECHO} "				for using port number <1024."
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
