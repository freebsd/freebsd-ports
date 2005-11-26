# $FreeBSD$
# bsd.linux.mk - support for RPM packages which install in ${LINUXBASE}
# Maintainer: Jean-Yves Lefort <jylefort@FreeBSD.org>

MASTER_SITES?=	${MASTER_SITE_FEDORA_LINUX}
PKGNAMEPREFIX?=	linux-
EXTRACT_SUFX?=	.${LINUX_ARCH}.rpm

EXTRACT_DEPENDS+=	rpm2cpio:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=	rpm2cpio
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

USE_LINUX=	yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

DESCR?=		${.CURDIR}/../${PORTNAME}/pkg-descr
MD5_FILE?=	${MASTERDIR}/distinfo.${ARCH}
PLIST?=		${WRKDIR}/.plist

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
LINUX_ARCH?=	x86_64
.elif ${ARCH} == "powerpc"
LINUX_ARCH?=	ppc
.else
LINUX_ARCH?=	${ARCH}
.endif

.if !target(pre-install)
pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} >> ${PLIST} && \
	${FIND} * -type d | ${SORT} -r \
		| ${GREP} -Ev '^(etc|lib|usr|usr/bin|usr/lib|usr/sbin|usr/share|usr/share/doc|usr/share/info|usr/share/man|usr/share/man/man[1-9n])$$' \
		| ${SED} -e 's|^|@dirrm |' >> ${PLIST}
.  if defined(INSTALLS_LINUX_SHLIB)
	@${ECHO_CMD} '@exec ${LINUXBASE}/sbin/ldconfig 2>/dev/null || true' >> ${PLIST}
	@${ECHO_CMD} '@unexec ${LINUXBASE}/sbin/ldconfig 2>/dev/null || true' >> ${PLIST}
.  endif
.endif

.if !target(do-install)
do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  if defined(INSTALLS_LINUX_SHLIB)
	-${LINUXBASE}/sbin/ldconfig
.  endif
.endif

.include <bsd.port.post.mk>
