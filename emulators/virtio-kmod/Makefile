# New ports collection makefile for:	virtio-kmod
# Date created:		20 Nov 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	virtio
PORTVERSION=	0.${SVN_REV}
CATEGORIES=	emulators
MASTER_SITES=	# none
PKGNAMESUFFIX=	-kmod
DISTFILES=	# none

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	virtio kernel modules port for 8.2/9.0

FETCH_DEPENDS=	svn:${PORTSDIR}/devel/subversion

ONLY_FOR_ARCHS=	amd64 i386

WRKSRC=		${WRKDIR}
SVN_REV=	227652
SVN_MIRROR?=	http://svn.freebsd.org/base
KMODDIR?=	modules
PLIST_SUB=	KMODDIR=${KMODDIR}
SVN=		${LOCALBASE}/bin/svn

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source to be installed
.endif

MANUAL_PACKAGE_BUILD=	pointyhat prohibits internet traffic outside fetch stage

.include <bsd.port.pre.mk>

.if ${OSREL} != "8.2" && ${OSREL} != "9.0"
IGNORE=		not supported $${OSREL} (${OSREL})
.endif

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} -Rp ${SRC_BASE}/sys ${WRKSRC}/
	cd ${WRKSRC}/sys/dev && ${SVN} co -r ${SVN_REV} ${SVN_MIRROR}/head/sys/dev/virtio
	cd ${WRKSRC}/sys/modules && ${SVN} co -r ${SVN_REV} ${SVN_MIRROR}/head/sys/modules/virtio

do-build:
	cd ${WRKSRC}/sys/modules/virtio; ${MAKE} DEBUG_FLAGS=-g

do-install:
	${MKDIR} ${PREFIX}/${KMODDIR}
.for f in pci/virtio_pci virtio/virtio block/virtio_blk balloon/virtio_balloon network/if_vtnet
	${INSTALL_KLD} ${WRKSRC}/sys/modules/virtio/${f}.ko ${PREFIX}/${KMODDIR}/
	${INSTALL_KLD} ${WRKSRC}/sys/modules/virtio/${f}.ko.symbols ${PREFIX}/${KMODDIR}/
.endfor

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
