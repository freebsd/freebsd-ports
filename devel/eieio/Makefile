# New ports collection makefile for:   eieio
# Date created:                10 December 2001
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	eieio
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	devel elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://bsdchat.com/dist/dryice/
MASTER_SITE_SUBDIR=	cedet
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
#DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/beta/}

MAINTAINER=	dryice@liu.com.cn
COMMENT=	Enhanced Integration of Emacs Interpreted Objects

EMACS_PORT_NAME?=	emacs21

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/speedbar/speedbar.el:${PORTSDIR}/editors/speedbar${PORTNAMESUFFIX}

USE_GMAKE=	yes
CONFLICTS=	cedet*
INFO=		eieio

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/eieio

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "New version of eieio is now in devel/cedet."
	@${ECHO_MSG} "Hit C-c now if you want the new version."
	@${ECHO_MSG} ""

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/eieio.info ${PREFIX}/info
	install-info ${PREFIX}/info/eieio.info ${PREFIX}/info/dir

.include <bsd.port.mk>
