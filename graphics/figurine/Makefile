# New ports collection makefile for:	figurine
# Date created:		15 September 2002
# Whom:			Marc Fonvieille <blackend@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	figurine
PORTVERSION=	1.0.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	blackend@FreeBSD.org
COMMENT=	A drawing program for X11

RUN_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig


GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_XPM=	yes

MAN1=		figurine.1

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|Doc examples src|src|" \
		${WRKSRC}/Makefile.in
.endif
	@${FIND} ${WRKSRC} -type f -name Makefile.in | \
		${XARGS} -n 10 ${REINPLACE_CMD} \
		-e 's|datadir = @datadir@|datadir = @datadir@/doc|'

.include <bsd.port.mk>
