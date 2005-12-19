#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	jylefort@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

MASTER_SITES?=			${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR?=	3/${LINUX_RPM_ARCH}/os/Fedora/RPMS/
PKGNAMEPREFIX?=			linux-

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "8" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		8
.    elif ${USE_LINUX} == "debian"
_LINUX_BASE_SUFFIX=		debian
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					"uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"8\" and \"debian\""
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm ' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}

.  endif

.  if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist:
	@${RM} -rf ${WRKDIR}/.new-plist
	@${MKDIR} ${WRKDIR}/.new-plist
	@cd ${WRKDIR}/.new-plist && \
	for f in ${DISTFILES}; do \
		${RPM2CPIO} ${_DISTDIR}/$$f | ${CPIO} -id --quiet; \
		${FIND} * ! type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
