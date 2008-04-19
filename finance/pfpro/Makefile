# New ports collection makefile for:	pfpro
# Date created:		November 29, 2005
# Whom:			durian@shadetreesoftware.com
#
# $FreeBSD$
#

PORTNAME=	pfpro
PORTVERSION=	3.0.8
PORTREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	#https://manager.verisign.com/
DISTNAME=	pfpro_freebsd

MAINTAINER=	never@nevermind.kiev.ua
COMMENT=	SDK for VeriSign's PayFlow Pro

ONLY_FOR_ARCHS=	i386
RESTRICTED=	Only for VeriSign PayFlow Pro customers
USE_LDCONFIG=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	pkg-message

PKGMESSAGE=	${WRKDIR}/pkg-message
LATEST_LINK=	verisign-pfpro

CERTDIR=	${PREFIX}/etc/pfpro/certs
FBSDDIR=	${WRKSRC}/verisign/payflowpro/freebsd
PATCH_WRKSRC=	${WRKSRC}/verisign/payflowpro/freebsd/bin
PFCFLAGS=	-DUSE_SSLEAY -fPIC -DFREEBSD_OS -DGENERIC_SEED  -D_REENTRANT -pthread -DPTHREADS -I. -L.

# XXX nees to be the same as DISTFILES
PFP_BUNDLE=	${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.pre.mk>

# Check for SDK bundle
.if !exists(${DISTDIR}/${PFP_BUNDLE})
ECHO_MSG=/usr/bin/printf
IGNORE=	:\n\
The VeriSign PayFlow Pro SDK is only available to customers who have\n\
subscribed to this service.  Please access your account at\n\
https://manager.verisign.com/ and retrieve the FreeBSD 5.x version\n\
of the SDK from the Downloads area.  You will be required to agree to\n\
some terms and conditions.  After downing the SDK, place ${PFP_BUNDLE}\n\
in ${DISTDIR}.\n
.endif

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${FBSDDIR}/bin/pfpro.c

do-build:
	(cd ${FBSDDIR}/lib && ${CC} ${PFCFLAGS} ${CFLAGS} -c ../bin/${PORTNAME}.c -o ${PORTNAME}.o && ${CC} ${PFCFLAGS} ${CFLAGS} -lpfpro ${PORTNAME}.o -o ${PORTNAME})

do-install:
	${INSTALL_PROGRAM} ${FBSDDIR}/lib/pfpro ${PREFIX}/bin
	${INSTALL_DATA} ${FBSDDIR}/lib/pfpro.h ${PREFIX}/include
	${INSTALL_DATA} ${FBSDDIR}/lib/libpfpro.so ${PREFIX}/lib
	${MKDIR} ${CERTDIR}
	${INSTALL_DATA} ${FBSDDIR}/certs/f73e89fd.0 ${CERTDIR}

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
