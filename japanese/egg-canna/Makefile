# New ports collection makefile for:	egg-canna
# Date created:		4 March 2005
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	egg-canna
PORTVERSION=	20011110
PORTREVISION=	12
CATEGORIES=	japanese editors elisp
MASTER_SITES=	http://cgi18.plala.or.jp/nyy/canna/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}.el
EXTRACT_SUFX=	# empty

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Canna Conversion Facility in Egg Input Method Architecture

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/egg/egg-sim.el:${PORTSDIR}/editors/tamago${EMACS_SUFFIX}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_EMACS=	yes

.include <bsd.port.pre.mk>

.if ${EMACS_PORT_NAME} == "emacs23" || ${EMACS_PORT_NAME} == "emacs24"
IGNORE=		does not build with Emacs 23 and later
.endif

.if ${EMACS_PORT_NAME} == emacs20
EMACS_SUFFIX=	${PKGNAMESUFFIX}
.else
EMACS_SUFFIX=	#
.endif

NO_WRKSUBDIR=	yes

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	.

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/${DISTNAME} \
		${EMACS_VERSION_SITE_LISPDIR}/${DISTNAME}c

do-build:
	@cd ${WRKDIR} && ${EMACS_CMD} -batch -q -no-site-file -no-init-file \
		-f batch-byte-compile ${DISTNAME}

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME} \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME}c \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

.include <bsd.port.post.mk>
