# Ports collection makefile for:  pear-Horde_Role
# Date created:			  6 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Horde_Role
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	devel www pear

MAINTAINER=	mm@FreeBSD.org
COMMENT=	PEAR installer role for Horde components

PATCH_WRKSRC=	${WRKDIR}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"

post-install:
	@${MKDIR} ${PREFIX}/${HORDE_DIR}
	@${TOUCH} ${PREFIX}/${HORDE_DIR}/.keep_me
	@${ECHO_CMD} "${HORDE_DIR}/.keep_me" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${PEAR} config-set horde_dir %D/${HORDE_DIR} system" >> \
		${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${HORDE_DIR} 2>/dev/null || true" >> \
		${TMPPLIST}
	@${ECHO_CMD} "===>   Configuring PEAR horde_dir"
	@${PEAR} config-set horde_dir ${PREFIX}/${HORDE_DIR} system

.include <bsd.port.post.mk>
