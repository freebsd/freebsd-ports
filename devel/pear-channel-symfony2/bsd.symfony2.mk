# $FreeBSD$

MASTER_SITES?=	http://pear.symfony.com/get/
PKGNAMEPREFIX?=	pear-

BUILD_DEPENDS+=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/pear.symfony.com.reg:${PORTSDIR}/devel/pear-channel-symfony2

RUN_DEPENDS+=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/pear.symfony.com.reg:${PORTSDIR}/devel/pear-channel-symfony2

DIST_SUBDIR=	Symfony2
PEAR_CHANNEL=	symfony2
PEAR_AUTOINSTALL=	yes

.if defined(USE_SYMFONY2_RUN)
. for DEP in ${USE_SYMFONY2_RUN}
.  if !defined(symfony2-${DEP}-DEPEND)
UNKNOWN_SYMFONY2_PACKAGES+=	${DEP}
.  else
RUN_DEPENDS+=	${symfony2-${DEP}-DEPEND}
.  endif
. endfor
.endif

.if defined(USE_SYMFONY2_BUILD)
. for DEP in ${USE_SYMFONY2_BUILD}
.  if !defined(symfony2-${DEP}-DEPEND)
UNKNOWN_SYMFONY2_PACKAGES+=	${DEP}
.  else
BUILD_DEPENDS+=	${symfony2-${DEP}-DEPEND}
.  endif
. endfor
.endif

.if defined(UNKNOWN_SYMFONY2_PACKAGES)
IGNORE=	unknown Symfony2 package(s): ${UNKNOWN_SYMFONY2_PACKAGES}
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"

