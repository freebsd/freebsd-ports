# New ports collection makefile for:	gruftistats
# Date created:		29 October 2001
# Whom:			Matthew West <mwest@uct.ac.za>
#
# $FreeBSD$
#

PORTNAME=	gruftistats
PORTVERSION=	0.2.4
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gruftistats

MAINTAINER=	mwest@uct.ac.za

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
