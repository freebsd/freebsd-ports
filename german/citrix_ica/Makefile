# New ports collection makefile for:	Citrix(R) ICA(R) Client
# Date created:         12 Dez 2000
# Whom:                 mblapp
#
# $FreeBSD$
#

PORTNAME=	citrix_ica
PORTVERSION=	6.0.92
CATEGORIES=	german net comms linux
MASTER_SITES=
DISTNAME=	linuxx86

MAINTAINER=	mb@imp.ch

RUN_DEPENDS=    /compat/linux/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386
RESTRICTED=	"License prohibits redistribution"
IS_INTERACTIVE=	"Noisy license agreement ignores stdin"

DIST_SUBDIR=	citrix_ica
NO_WRKSUBDIR=	Yes
NO_BUILD=       Yes

CDIR=	${PREFIX}/ICAClient
BINDIR=		${PREFIX}/bin

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE='The distribution file for this port may not be automatically fetched due to licensing restrictions.  You MUST fetch the file manually after reading and agreeing to the license at: http://www.citrix.com/download/bin/license.asp?client=linux   Once ${DISTFILES} has been downloaded, move it to ${DISTDIR}/${DIST_SUBDIR} and then restart this build.'
.endif

do-install:
	${SED} s%DESTINATION%${CDIR}% < ${FILESDIR}/response \
		> ${WRKSRC}/response
	${SED} s%DESTINATION%${CDIR}% < ${FILESDIR}/wfcmgr \
		> ${WRKSRC}/wfcmgr.x
	${SED} s%DESTINATION%${CDIR}% < ${FILESDIR}/wfica \
		> ${WRKSRC}/wfica.x
	cd ${WRKSRC} && ${LINUXBASE}/bin/sh -c './setupwfc < response'
	${INSTALL_SCRIPT} ${WRKSRC}/wfcmgr.x ${PREFIX}/bin/wfcmgr
	${INSTALL_SCRIPT} ${WRKSRC}/wfica.x ${PREFIX}/bin/wfica

.include <bsd.port.post.mk>
