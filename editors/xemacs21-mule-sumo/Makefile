# New ports collection makefile for:   Meta port of XEmacs mule with sumo package
# Date created:        19 August 1999
# Whom:                KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xemacs-${NAMEPREFIX}sumo
PORTVERSION=	${XEMACS_REL}
CATEGORIES+=	editors
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	kiri@pis.toba-cmt.ac.jp

RUN_DEPENDS=	${LOCALBASE}/lib/xemacs/xemacs-packages/pkginfo/MANIFEST.zenirc:${PORTSDIR}/editors/xemacs-sumo-packages \
		${LOCALBASE}/lib/xemacs/mule-packages/pkginfo/MANIFEST.skk:${PORTSDIR}/editors/xemacs-mule-sumo-packages \
		${RUN_DEP_LIST}

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

XEMACS_MAJOR_VER=	21
XEMACS_REL=		21.1
XEMACS_VER=		21.1.9
XEMACS_ARCH=		${MACHINE_ARCH}--freebsd

.include <bsd.port.pre.mk>

.if defined(PKGNAMEPREFIX) && (${PKGNAMEPREFIX} == "ja-")
RUN_DEP_LIST=		${LOCALBASE}/lib/xemacs-${XEMACS_VER}/${XEMACS_ARCH}/config.values:${PORTSDIR}/japanese/xemacs${XEMACS_MAJOR_VER}${PKGNAMESUFFIX}
.else
RUN_DEP_LIST=		${LOCALBASE}/lib/xemacs-${XEMACS_VER}/${XEMACS_ARCH}/config.values:${PORTSDIR}/editors/xemacs${XEMACS_MAJOR_VER}-mule
NAMEPREFIX=		mule-
.endif

do-install:		# empty

.include <bsd.port.post.mk>
