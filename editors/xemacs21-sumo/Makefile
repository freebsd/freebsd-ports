# New ports collection makefile for:   Meta port of XEmacs mule with sumo package
# Version required:	21.1.8
# Date created:        19 August 1999
# Whom:                KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	xemacs-${NAMEPREFIX}sumo${NAMEEXT}-${XEMACS_VER}
PKGNAME=	${LANGPREFIX}${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	kiri@pis.toba-cmt.ac.jp

RUN_DEPENDS=	${PREFIX}/lib/xemacs/xemacs-packages/pkginfo/MANIFEST.zenirc:${PORTSDIR}/editors/xemacs-sumo-packages \
		${PREFIX}/lib/xemacs/mule-packages/pkginfo/MANIFEST.skk:${PORTSDIR}/editors/xemacs-mule-sumo-packages \
		${RUN_DEP_LIST}

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

XEMACS_VER=	21.1.8
XEMACS_DIR=	xemacs-${XEMACS_VER}
ARCH_SUBDIR=	${MACHINE_ARCH}--freebsd

.if defined(LANGPREFIX) && (${LANGPREFIX} == "ja-")
RUN_DEP_LIST=	${PREFIX}/lib/${XEMACS_DIR}/${ARCH_SUBDIR}/config.values:${PORTSDIR}/japanese/xemacs${NAMEEXT}
.else
RUN_DEP_LIST=	${PREFIX}/lib/${XEMACS_DIR}/${ARCH_SUBDIR}/config.values:${PORTSDIR}/editors/xemacs-mule
NAMEPREFIX=	mule-
.endif

do-install:	# empty

.include <bsd.port.mk>
