# New ports collection makefile for:	wxdfast
# Date created:				2006-11-07
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	wxdfast
PORTVERSION=	0.5.4
CATEGORIES=	ftp www
MASTER_SITES=	SF/dfast
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A great multithreaded and multi-platform download manager

USE_GETTEXT=	yes
USE_WX=		2.6
WX_CONF_ARGS=	relative
WX_UNICODE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir="${MANPREFIX}/man"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		wxdfast.1

post-patch:
	@${REINPLACE_CMD} -e 's|wxrc|${WXRC_CMD:T}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|pt_BR||' ${WRKSRC}/man/Makefile.in

.include <bsd.port.mk>
