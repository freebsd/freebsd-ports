# New ports collection makefile for:	bglibs
# Date created:		03 Mar 2003
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	bglibs
PORTVERSION=	1.007
CATEGORIES=	devel
MASTER_SITES=	http://untroubled.org/bglibs/

MAINTAINER=	sergei@kolobov.com
COMMENT=	One stop library package by Bruce Guenter

USE_REINPLACE=	yes

BGLIBS_ROOT?=	${PREFIX}

DOCS=		NEWS README TODO

pre-build:
	${ECHO_CMD} ${BGLIBS_ROOT}   > ${WRKSRC}/conf-home
	${ECHO_CMD} ${CC} ${CFLAGS}  > ${WRKSRC}/conf-cc
	${REINPLACE_CMD}  -e 's/^int msg_show_pid/const int msg_show_pid/' \
		${WRKSRC}/msg/common.c

do-install:
	cd ${WRKSRC} && ./installer
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
