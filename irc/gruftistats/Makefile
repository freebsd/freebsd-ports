# New ports collection makefile for:	gruftistats
# Date created:		29 October 2001
# Whom:			Matthew West <mwest@uct.ac.za>
#
# $FreeBSD$
#

PORTNAME=	gruftistats
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gruftistats

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Produces a web page of statistics and quotes from IRC channel logs

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_REINPLACE=	yes

.if defined(NOPORTDOCS)
MAKE_ARGS=	NOPORTDOCS=1
.endif

MAN1=		gruftistats.1

post-patch:
	@${REINPLACE_CMD} -e \
		's,strcasestr,strcasestr_x,g' ${WRKSRC}/ircstats.h \
		${WRKSRC}/lib.c

.include <bsd.port.mk>
