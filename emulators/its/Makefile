# New ports collection makefile for:   its
# Date created:        11 January 2002
# Whom:                kstailey
#
# $FreeBSD$
#

PORTNAME=	its
PORTVERSION=	1.0
CATEGORIES=	emulators
MASTER_SITES=	http://filbert.tubas.net/~kstailey/ITS/ \
		http://free.babolo.ru/src/ \
		http://dl.droso.net/FreeBSD/distfiles/
DISTNAME=	PI-ITS-RP06.0-dbd9
EXTRACT_SUFX=	.bz2
EXTRACT_ONLY=	# none

MAINTAINER=	kstailey@yahoo.com
COMMENT=	Bootable ITS filesystem for KLH-10 PDP-10 emulator

BUILD_DEPENDS=	kn10-ks:${PORTSDIR}/emulators/klh10
RUN_DEPENDS=	kn10-ks:${PORTSDIR}/emulators/klh10

ONLY_FOR_ARCHS=	i386	# really KLH10 has this problem.

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_PACKAGE=	PI ITS RP06 disk image is too big.
NO_CDROM=	PI ITS RP06 disk image is too big.

# KSITS_KLH10_HOME and KSITS_DRIVER_DIR must be set to the same locations
# that the klh10 port uses
KSITS_KLH10_DIR=	klh10-ks-its
KLH10_HOME=		${PREFIX}/share/${KSITS_KLH10_DIR}
KSITS_DRIVER_DIR=	${PREFIX}/libexec/${KSITS_KLH10_DIR}
IMAGE_HOME?=		${KLH10_HOME}
IMAGE_NAME=		PI-ITS-RP06.0-dbd9
IMAGE_BZ2=		${IMAGE_NAME}.bz2
DOCDIR=			${PREFIX}/share/doc/${KSITS_KLH10_DIR}
PLIST_SUB+=		IMAGE_HOME=${IMAGE_HOME}

do-install:
	@ ${ECHO} Installing compressed PI ITS RP06 disk image in ${IMAGE_HOME}
.if (${IMAGE_HOME} == ${KLH10_HOME})
	@ ${ECHO} Use IMAGE_HOME=/my/directory to relocate.
.endif
	@ ${MKDIR} ${IMAGE_HOME}
	@ ${INSTALL_DATA} ${DISTDIR}/${IMAGE_BZ2} ${IMAGE_HOME}/${IMAGE_BZ2}
	@ ${INSTALL_DATA} ${FILESDIR}/klh10-kn-freebsd.ini.in ${KLH10_HOME}
	@ ${INSTALL_SCRIPT} ${FILESDIR}/its.sh ${PREFIX}/bin/its
	@ ${SED} -e "s;@PI-IMG@;${IMAGE_NAME};g" \
		 -e "s;@KLH-SHARE@;${KLH10_HOME};g" \
		 -e "s;@KLH-LIBEX@;${KSITS_DRIVER_DIR};g" \
		${FILESDIR}/its-user-install.sh > ${WRKSRC}/its-user-install
	@ ${INSTALL_SCRIPT} ${WRKSRC}/its-user-install ${PREFIX}/bin
	@ ${INSTALL_MAN} ${FILESDIR}/MIT-ITS-papers ${DOCDIR}
	@ ${SED} -e "s;@PREFIX@;${PREFIX};g" \
		${FILESDIR}/README.FIRST >${WRKSRC}/README.FIRST
	@ ${INSTALL_MAN} ${WRKSRC}/README.FIRST ${DOCDIR}
	@ ${ECHO} "***  Please read ${DOCDIR}/README.FIRST"

.include <bsd.port.mk>
