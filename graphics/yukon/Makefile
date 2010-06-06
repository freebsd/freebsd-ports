# New ports collection makefile for:	yukon
# Date created:		12th January 2010
# Whom:			bms
#
# $FreeBSD$
#
# TODO: roll svn tarball, add patches with sedification.

PORTNAME=	yukon
PORTVERSION=	2010011201
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bms
DISTNAME=	yukon-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time capture tool for OpenGL applications

BUILD_DEPENDS=	${LOCALBASE}/include/seom/seom.h:${PORTSDIR}/graphics/seom
LIB_DEPENDS=	seom.0:${PORTSDIR}/graphics/seom

NOMAN=		defined

USE_BZIP2=	yes
USE_GCC=	4.2+
USE_GMAKE=	yes
USE_XORG=	x11 xv
USE_GL=		yes
USE_LDCONFIG=	${PREFIX}/lib/yukon

MAKE_JOBS_SAFE=	defined

# NOTE: These should be bumped if the underlying GL or Xorg ports change.
LIBGL_MAJOR=	1
LIBX11_MAJOR=	6

MAKE_ENV+=	LIBGL_MAJOR="${LIBGL_MAJOR}" LIBX11_MAJOR="${LIBX11_MAJOR}"
PLIST_SUB+=	LIBGL_MAJOR="${LIBGL_MAJOR}" LIBX11_MAJOR="${LIBX11_MAJOR}"

#
# To roll snapshot: as bms: make BOOTSTRAP=defined fetch
#
.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
SVN_REV=	158		# svn tip at epoch 2009120801
SVNROOT_URI=	https://devel.neopsis.com/svn/yukon

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

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/yukon,${PREFIX}/etc/yukon,' \
	    ${WRKSRC}/src/core/conf.c ${WRKSRC}/src/scripts/yukon

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} \
	    ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
	@(${MKDIR} ${PREFIX}/etc/yukon/system)
	@(${PRINTF} >> ${TMPDIR}/yukon-system-conf \
	    'LDPATH="%s"\n' ${PREFIX}/lib/yukon)
	@(${INSTALL_DATA} ${TMPDIR}/yukon-system-conf \
	    ${PREFIX}/etc/yukon/system/default)
	@(${INSTALL_DATA} ${WRKSRC}/tools/yukon.conf \
	    ${PREFIX}/etc/yukon/conf.sample)

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
IGNORE=		unsupported on FreeBSD versions prior to 7.0
.endif

.include <bsd.port.post.mk>
