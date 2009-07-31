# New ports collection makefile for:	gkrellmoon
# Date Created:				Tue Jun 26 18:04:37 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	gkrellmoon
PORTVERSION=	0.3
PORTREVISION=	6
CATEGORIES=	astro
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A moon clock plugin for Gkrellm

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

USE_GNOME=	imlib

MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
ALL_TARGET=	${PORTNAME}.so

PORTSCOUT=	limit:^0\.3\.

post-install:
.ifndef(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE} \
		${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PORTNAME}
.endif #NOPORTDOCS

.include <bsd.port.mk>
