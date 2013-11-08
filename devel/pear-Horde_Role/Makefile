# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Horde_Role
PORTVERSION=	1.0.1
CATEGORIES=	devel www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	PEAR installer role for Horde components

PATCH_WRKSRC=	${WRKDIR}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${HORDE_DIR}
	@${TOUCH} ${STAGEDIR}${PREFIX}/${HORDE_DIR}/.keep_me
	@${ECHO_CMD} "${HORDE_DIR}/.keep_me" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${HORDE_DIR} 2>/dev/null || true" >> \
		${TMPPLIST}

.include <bsd.port.post.mk>
