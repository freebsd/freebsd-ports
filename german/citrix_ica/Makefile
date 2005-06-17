# New ports collection makefile for:	Citrix(R) ICA(R) Client
# Date created:         12 Dez 2000
# Whom:                 mblapp
#
# $FreeBSD$
#

PORTNAME=	citrix_ica
PORTVERSION=	6.30.1054
PORTREVISION=	3
CATEGORIES=	german net comms linux
MASTER_SITES=
DISTNAME=	${PORTNAME}-linuxx86-de

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	Citrix(R) client for the Microsoft Windows Terminal Server

ONLY_FOR_ARCHS=	i386
RESTRICTED=	"License prohibits redistribution"
IS_INTERACTIVE=	"Noisy license agreement ignores stdin"

NO_WRKSUBDIR=	Yes
NO_BUILD=	Yes
USE_LINUX=	Yes
USE_X_PREFIX=	Yes

CDIR=	${PREFIX}/ICAClient
BINDIR=		${PREFIX}/bin

NSCP=	/usr/local/libexec/netscape \
	/usr/local/libexec/netscape-linux \
	/usr/local/netscape \
	/usr/local/netscape-linux \
	/usr/local/lib/netscape \
	/usr/local/lib/netscape-linux \
	${MOZILLA_HOME}

.include <bsd.port.pre.mk>

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE='The distribution file for this port may not be automatically fetched due to licensing restrictions.'
.endif

do-fetch:
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
	@${ECHO} ""
	@${ECHO} "You have to fetch the file manually after reading and"
	@${ECHO} "agreeing to the license at:"
	@${ECHO} ""
	@${ECHO} "http://www.citrix.com/download/bin/license.asp?client=linux"
	@${ECHO} ""
	@${ECHO} "Once linuxx86.tar.gz has been downloaded move it to"
	@${ECHO} "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} and restart the build."
	@${ECHO} ""
	@${FALSE}
.endif

do-install:
	@if (test -d "${CDIR}") ; \
	then \
		${ECHO} "-----------------------------------------------------------" ; \
		${ECHO} "" ; \
		${ECHO} "A ${CDIR} installation does already exist." ; \
		${ECHO} "Please move it away or delete the old port" ; \
		${ECHO} "" ; \
		${ECHO} "-----------------------------------------------------------" ; \
		${FALSE} ; \
	fi

	@${ECHO_CMD} -e "1\n${CDIR}\nj\nj\nj\nj\n3" > ${WRKSRC}/response ;
	@for dir in ${NSCP}; do \
                if [ -e $${dir}/plugins/libnullplugin.so ]; then \
                        BIN=`${FILE} $${dir}/plugins/libnullplugin.so | ${AWK} '{print $$11}'` ; \
                        case $${BIN} in \
                        \(SYSV\),) \
				${ECHO_CMD} -e "1\n${CDIR}\nj\nj\nj\n3" > ${WRKSRC}/response ; \
                        esac \
                fi \
        done

	${SED} s%DESTINATION%${CDIR}% < ${FILESDIR}/wfcmgr \
		> ${WRKSRC}/wfcmgr.x
	${SED} s%DESTINATION%${CDIR}% < ${FILESDIR}/wfica \
		> ${WRKSRC}/wfica.x
	cd ${WRKSRC} && ${LINUXBASE}/bin/sh -c './setupwfc < response'
	${INSTALL_SCRIPT} ${WRKSRC}/wfcmgr.x ${PREFIX}/bin/wfcmgr
	${INSTALL_SCRIPT} ${WRKSRC}/wfica.x ${PREFIX}/bin/wfica
# XXX: This is missing a "${BRANDELF} -t Linux <executables>".

.include <bsd.port.post.mk>
