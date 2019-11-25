# $FreeBSD$

PORTNAME=	libopenbsd
PORTVERSION=	r298107
CATEGORIES=	devel
MASTER_SITES=	LOCAL/jbeich \
		https://svn.freebsd.org/base/head/lib/${PORTNAME}/:svn

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	imsg and ohash routines from OpenBSD libutil

LICENSE=	ISCL

USES=		uidfix tar:xz
MAKE_ENV=	SHLIB_MAJOR=0 WITHOUT_PROFILE=1
MAKE_ARGS=	INCLUDEDIR="${PREFIX}/include" LIBDIR="${PREFIX}/lib" \
		MANDIR="${PREFIX}/man/man"
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

#
# To update snapshot: make makesum BOOTSTRAP=
# Specific snapshot:  make makesum SVN_FETCH= PORTVERSION=r1234
#
.if defined(BOOTSTRAP)
SVN_REV!=	svn info ${MASTER_SITES:M*\:svn:S/:svn//} | \
		${SED} -n 's/^Last Changed Rev: //p'
PORTVERSION:=	r${SVN_REV}
.else
SVN_REV?=	${PORTVERSION:S/r//}
.endif

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+=	svn:devel/subversion

NO_CHECKSUM=	yes

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r${SVN_REV} ${_MASTER_SITES_svn} ${WRKSRC}
	(cd ${WRKDIR} && ${TAR} cJvf \
		${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		--uid 0 --gid 0 ${DISTNAME})
. ifmake makesum
	${REINPLACE_CMD} -i '' '/^PORTVERSION=/s/r.*/r${SVN_REV}/' \
		${MASTERDIR}/Makefile
. endif
. if ${USER} == ${MAINTAINER:C/@.*//}
	-scp ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		freefall.freebsd.org:public_distfiles/
. endif
.endif

.include <bsd.port.mk>
