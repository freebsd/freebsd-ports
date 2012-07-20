# New ports collection makefile for:	virtio-kmod
# Date created:		20 Nov 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	virtio
PORTVERSION=	0.${SVN_REV}
PORTREVISION=	1
CATEGORIES=	emulators kld
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
PKGNAMESUFFIX=	-kmod

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	virtio kernel modules port for 8.[23]/9.0

ONLY_FOR_ARCHS=	amd64 i386

WRKSRC=		${WRKDIR}
SVN_REV=	234349
KMODDIR?=	/boot/modules
PLIST_SUB=	KMODDIR=${KMODDIR:C,^/,,}
NEEDSUBDIRS=	amd64 conf contrib dev/pci geom i386 kern net netinet netinet6 \
	sys tools vm x86

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source to be installed
.endif

.if ${OSREL} != "8.2" && ${OSREL} != "8.3" && ${OSREL} != "9.0"
IGNORE=		not supported $${OSREL} (${OSREL})
.endif
.if ${OSREL} == "8.2"
SVN_REV=	228301
#SVN_REV=	232470
#SVN_REV=	228301
.endif

post-extract:
	cd ${WRKSRC} && ${MKDIR} sys/dev tmp && ${MV} dev modules tmp/
.for d in ${NEEDSUBDIRS}
	${CP} -Rp ${SRC_BASE}/sys/${d} ${WRKSRC}/sys/${d}
.endfor
	${CP} -Rp ${WRKSRC}/tmp/* ${WRKSRC}/sys/

do-build:
	cd ${WRKSRC}/sys/modules/virtio; ${MAKE} DEBUG_FLAGS=-g

do-install:
.for f in pci/virtio_pci virtio/virtio block/virtio_blk balloon/virtio_balloon network/if_vtnet
	${INSTALL_KLD} ${WRKSRC}/sys/modules/virtio/${f}.ko ${KMODDIR}
	${INSTALL_KLD} ${WRKSRC}/sys/modules/virtio/${f}.ko.symbols ${KMODDIR}
.endfor
	/usr/sbin/kldxref ${KMODDIR}

post-install:
	${CAT} ${PKGMESSAGE}

# For maintainer only.
SVN_MIRROR?=	http://svn.freebsd.org/base
EXPDIR=		${WRKSRC}/src/sys
maintainer-tar:
	${MKDIR} ${EXPDIR}
	cd ${EXPDIR} && svn export -r ${SVN_REV} ${SVN_MIRROR}/head/sys/dev/virtio dev/virtio
	cd ${EXPDIR} && svn export -r ${SVN_REV} ${SVN_MIRROR}/head/sys/modules/virtio modules/virtio
	cd ${EXPDIR} && ${TAR} cfvz ${DISTDIR}/${DISTFILES} dev modules

maintainer-check:
	@new=`svn log -ql 1 ${SVN_MIRROR}@HEAD head/sys/dev/virtio | ${GREP} -v ^- | ${SED} -e 's| .*||'`;\
	old="r${SVN_REV}";\
	if [ "$${new}" != "$${old}" ]; then ${ECHO_MSG} "New virtio rev: $${new}"; fi

.include <bsd.port.post.mk>
