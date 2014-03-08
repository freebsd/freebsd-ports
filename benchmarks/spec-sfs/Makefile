# Created by: Craig Rodrigues <rodrigc@FreeBSD.org>
# $FreeBSD$
#
# Based on port originally created by Garrett Cooper <gcooper@FreeBSD.org>
#

PORTNAME=	spec-sfs
PORTVERSION=	2008
CATEGORIES=	benchmarks java
DISTNAME=	SPECsfs2008-1.00
EXTRACT_SUFX=	.iso

MAINTAINER=	rodrigc@FreeBSD.org
COMMENT=	SPEC NFS and CIFS filesystem benchmark suite

NO_PACKAGE=	license restricts redistribution
RESTRICTED=	license restricts redistribution

USES=	gmake perl5
USE_PERL5=	run
USE_JAVA=	yes
JAVA_VERSION=	1.6+

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}
BUILD_WRKSRC=	${WRKSRC}/spec-sfs2008
DOWNLOAD_URL?=	http://www.spec.org/sfs2008/
SPEC_ROOT?=	${PREFIX}/${PORTNAME}

DOCSDIR=	${SPEC_ROOT}/documents

OPTIONS=	RESERVED_PORT	"Use privileged ports when doing NFS testing" on

.if defined(WITH_RESERVED_PORT)
CFLAGS+=	-DRESVPORT
.endif

# Substitutions for pkg-plist
PLIST_SUB+=	SPEC_ROOT=${SPEC_ROOT}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE?=You must purchase ${DISTFILES} from SPEC (${DOWNLOAD_URL}), place it in ${DISTDIR} and then run make again
.endif

pre-install:
	${FIND} ${WRKDIR} -name "*\.orig" -delete

do-install:
	cd ${WRKDIR}/spec-sfs2008/manager && ${JAVA} SpecInstall ${SPEC_ROOT}
	${RM} -fr ${SPEC_ROOT}/binaries
	${CHMOD} g+w ${SPEC_ROOT}/result

post-install:
	@${ECHO_CMD}
	@${CAT} ${WRKDIR}/${PKGMESSAGE:T}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
