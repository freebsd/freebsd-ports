# $FreeBSD$

PORTNAME=	virtio
PORTVERSION=	0.${SVN_REV}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
PKGNAMESUFFIX=	-kmod-${OSBRANCH}
DISTFILES=	${FILE_8} ${FILE_9}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	virtio kernel modules port for 8.[234]/9.[01]

ONLY_FOR_ARCHS=	amd64 i386

WRKSRC=		${WRKDIR}
NEEDSUBDIRS=	amd64 cam conf contrib dev/pci geom i386 kern net netinet netinet6 \
	sys tools vm x86

NO_STAGE=	yes

USES=		kmod
.include <bsd.port.pre.mk>

SVN_REV=	250249
FILE_8=		${PORTNAME}-8-0.${SVN_REV}${EXTRACT_SUFX}
FILE_9=		${PORTNAME}-9-0.${SVN_REV}${EXTRACT_SUFX}
.if ${OSREL} == "8.2"
OSBRANCH=	8.2
EXTRACT_ONLY=	${FILE_8}
.elif ${OSREL} == "8.3"
OSBRANCH=	8.3
EXTRACT_ONLY=	${FILE_8}
.elif ${OSREL} == "8.4"
OSBRANCH=	8.4
EXTRACT_ONLY=	${FILE_8}
.elif ${OSREL} == "9.0"
OSBRANCH=	9.0
EXTRACT_ONLY=	${FILE_9}
.elif ${OSREL} == "9.1"
OSBRANCH=	9.1
EXTRACT_ONLY=	${FILE_9}
.else
IGNORE=		not supported $${OSREL} (${OSREL})
.endif

post-extract:
	cd ${WRKSRC} && ${MKDIR} sys/dev tmp && ${MV} dev modules tmp/
.for d in ${NEEDSUBDIRS}
	[ ! -d ${SRC_BASE}/sys/${d} ] || ${CP} -Rp ${SRC_BASE}/sys/${d} ${WRKSRC}/sys/${d}
.endfor
	${CP} -Rp ${WRKSRC}/tmp/* ${WRKSRC}/sys/
.if ${OSREL} == "8.1" || ${OSREL} == "8.2"
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-virtio.h
.endif

do-build:
	cd ${WRKSRC}/sys/modules/virtio; ${MAKE} DEBUG_FLAGS=-g

do-install:
.for f in pci/virtio_pci virtio/virtio block/virtio_blk balloon/virtio_balloon network/if_vtnet
	${INSTALL_KLD} ${WRKSRC}/sys/modules/virtio/${f}.ko ${KMODDIR}
	${INSTALL_KLD} ${WRKSRC}/sys/modules/virtio/${f}.ko.symbols ${KMODDIR}
.endfor

post-install:
	${CAT} ${PKGMESSAGE}

# For maintainer only.
SVN_MIRROR?=	http://svn.freebsd.org/base
EXPDIR=		${WRKSRC}/src/sys
maintainer-tar:
	${MKDIR} ${EXPDIR}
	cd ${EXPDIR} && svn export -r ${SVN_REV} ${SVN_MIRROR}/stable/9/sys/dev/virtio dev/virtio
	cd ${EXPDIR} && svn export -r ${SVN_REV} ${SVN_MIRROR}/stable/9/sys/modules/virtio modules/virtio
	cd ${EXPDIR} && ${TAR} cfvz ${DISTDIR}/${FILE_9} dev modules
	cd ${EXPDIR} && ${RM} -rf dev modules
	cd ${EXPDIR} && svn export -r ${SVN_REV} ${SVN_MIRROR}/stable/8/sys/dev/virtio dev/virtio
	cd ${EXPDIR} && svn export -r ${SVN_REV} ${SVN_MIRROR}/stable/8/sys/modules/virtio modules/virtio
	cd ${EXPDIR} && ${TAR} cfvz ${DISTDIR}/${FILE_8} dev modules

maintainer-check:
	@new9=`svn log -ql 1 ${SVN_MIRROR}@HEAD stable/9/sys/dev/virtio | ${GREP} -v ^- | ${SED} -e 's| .*||; s|r||'`;\
	new8=`svn log -ql 1 ${SVN_MIRROR}@HEAD stable/8/sys/dev/virtio | ${GREP} -v ^- | ${SED} -e 's| .*||; s|r||'`;\
	old="${SVN_REV}";\
	if [ "$${new9}" -gt "$${old}" ]; then ${ECHO_MSG} "New virtio rev: r$${new9} (was $${old}, 8-stable is $${new8})"; fi

.include <bsd.port.post.mk>
