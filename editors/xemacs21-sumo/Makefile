# New ports collection makefile for:   Meta port of XEmacs with sumo package
# Date created:        19 August 1999
# Whom:                KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xemacs-${NAMEPREFIX}sumo
PORTVERSION=	${XEMACS_VER}
CATEGORIES+=	editors
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	kiri@FreeBSD.org

RUN_DEPENDS=	${RUN_DEP_LIST}
# below line would be remove comment and add RUN_DEPNDS after any xemacs-*-packages added
#		${LOCALBASE}/share/doc/xemacs-additional-packages:${PORTSDIR}/editors/xemacs-additional-packages \

NO_BUILD=	yes

XEMACS_MAJOR_VER=	21
XEMACS_REL=		21.1
XEMACS_VER=		21.1.14
XEMACS_ARCH=		${MACHINE_ARCH}--freebsd

do-install:		# empty

.include <bsd.port.pre.mk>

.if defined(PKGNAMEPREFIX) && ${PKGNAMEPREFIX} == "ja-"
RUN_DEP_LIST=		${LOCALBASE}/lib/xemacs-${XEMACS_VER}/${XEMACS_ARCH}/config.values:${PORTSDIR}/japanese/xemacs${XEMACS_MAJOR_VER}${PKGNAMESUFFIX}
.elif defined(NAMEPREFIX) && ${NAMEPREFIX} == "mule-"
RUN_DEP_LIST=		${LOCALBASE}/lib/xemacs-${XEMACS_VER}/${XEMACS_ARCH}/config.values:${PORTSDIR}/editors/xemacs${XEMACS_MAJOR_VER}-mule
NAMEPREFIX=		mule-
.else
RUN_DEP_LIST=		${LOCALBASE}/lib/xemacs-${XEMACS_VER}/${XEMACS_ARCH}/config.values:${PORTSDIR}/editors/xemacs${XEMACS_MAJOR_VER}
.endif

.include <bsd.port.post.mk>
