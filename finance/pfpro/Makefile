# New ports collection makefile for:	pfpro
# Date created:		November 29, 2005
# Whom:			durian@shadetreesoftware.com
#
# $FreeBSD$
#

PORTNAME=	pfpro
PORTVERSION=	3.0.8
CATEGORIES=	finance
MASTER_SITES=	#https://manager.verisign.com/
DISTNAME=	pfpro_freebsd

MAINTAINER=	durian@shadetreesoftware.com
COMMENT=	SDK for VeriSign's PayFlow Pro

ONLY_FOR_ARCHS=	i386
RESTRICTED=	"Only for VeriSign PayFlow Pro customers"
NO_BUILD=	yes
INSTALLS_SHLIB=	yes
NO_WRKSUBDIR=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

CERTDIR=	${PREFIX}/certs

FBSDDIR=	${WRKSRC}/verisign/payflowpro/freebsd

# XXX nees to be the same as DISTFILES
PFP_BUNDLE=	${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.pre.mk>

# Check for SDK bundle
.if !exists(${DISTDIR}/${PFP_BUNDLE})
ECHO_MSG=/usr/bin/printf
IGNORE= :\n\
The VeriSign PayFlow Pro SDK is only available to customers who have\n\
subscribed to this service.  Please access your account at\n\
https://manager.verisign.com/ and retrieve the FreeBSD 5.x version\n\
of the SDK from the Downloads area.  You will be required to agree to\n\
some terms and conditions.  After downing the SDK, place ${PFP_BUNDLE}\n\
in ${DISTDIR}.\n
.endif

post-patch:
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${.CURDIR}/pkg-message \
	    > ${PKGMESSAGE}

do-install:
	${INSTALL_PROGRAM} ${FBSDDIR}/bin/pfpro ${PREFIX}/bin
	${INSTALL_PROGRAM} ${FBSDDIR}/bin/pfpro-file ${PREFIX}/bin
	${INSTALL_DATA} ${FBSDDIR}/lib/pfpro.h ${PREFIX}/include
	${INSTALL_DATA} ${FBSDDIR}/lib/libpfpro.so ${PREFIX}/lib
	${MKDIR} ${CERTDIR}
	${INSTALL_DATA} ${FBSDDIR}/certs/f73e89fd.0 ${CERTDIR}

.include <bsd.port.post.mk>
