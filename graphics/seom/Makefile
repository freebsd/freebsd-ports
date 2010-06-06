# New ports collection makefile for:	seom
# Date created:		12th January 2010
# Whom:			bms
#
# $FreeBSD$
#

PORTNAME=	seom
PORTVERSION=	2010011201
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bms
DISTNAME=	seom-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time capture library for OpenGL applications

NOMAN=		defined

USE_BZIP2=	yes
USE_GCC=	4.2+
USE_GMAKE=	yes
USE_XORG=	x11 xv
USE_GL=		yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	"not yet ported to anything other than i386 and amd64"

.if ${ARCH} == "i386"
BROKEN=		does not build
.endif

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
BUILD_DEPENDS=	${LOCALBASE}/bin/yasm:${PORTSDIR}/devel/yasm
.endif

MAKE_JOBS_SAFE=	defined
MAKE_ENV+=	DATADIR="${DATADIR}" PREFIX="${PREFIX}"

#
# To roll snapshot: as bms: make BOOTSTRAP=defined fetch
#
.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
SVN_REV=	196		# svn tip at epoch 2009120801
SVNROOT_URI=	https://devel.neopsis.com/svn/seom

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} ${SVNROOT_URI}/trunk ${WRKSRC}
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
.if ${USER} == bms
	${CHMOD} ugo+r ${DISTDIR}/${DISTNAME}.tar.bz2
	scp -p ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    freefall.freebsd.org:public_distfiles/
.endif
.endif # defined(BOOTSTRAP)

.if ${OSVERSION} < 700000
IGNORE=		unsupported on FreeBSD versions prior to 7.0
.endif

.include <bsd.port.post.mk>
