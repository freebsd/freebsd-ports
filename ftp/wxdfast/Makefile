# New ports collection makefile for:	wxdfast
# Date created:				2006-11-07
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	wxdfast
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	ftp www
MASTER_SITES=	SF/dfast/wxDownload%20Fast/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A great multithreaded and multi-platform download manager

USE_GETTEXT=	yes
USE_WX=		2.6
WX_CONF_ARGS=	relative
WX_UNICODE=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		wxdfast.1

post-patch:
	@${REINPLACE_CMD} -e 's|wxrc|${WXRC_CMD:T}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|pt_BR||' ${WRKSRC}/man/Makefile.in

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000 && ${ARCH} == i386
BROKEN=	Does not compile
.endif

.include <bsd.port.post.mk>
