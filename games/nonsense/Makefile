# New ports collection makefile for:	nonsense
# Date created:		15 December 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	nonsense
PORTVERSION=	0.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A nonsense text generator

NO_BUILD=	defined
USE_REINPLACE=	yes

MAN6=		nonsense.6

post-configure:
		${REINPLACE_CMD} -e "s,/usr/local,${PREFIX}," ${WRKSRC}/nonsense
		${SED} -e "s^%%PREFIX%%^${PREFIX}^g" \
			< ${FILESDIR}/${MAN6} > ${WRKSRC}/${MAN6}

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/nonsense ${PREFIX}/bin
		${MKDIR} ${PREFIX}/share/nonsense/data
		${MKDIR} ${PREFIX}/share/nonsense/template
		${INSTALL_DATA} ${WRKSRC}/*.data ${PREFIX}/share/nonsense/data
		${INSTALL_DATA} ${WRKSRC}/*.template ${PREFIX}/share/nonsense/template
		${INSTALL_MAN} ${WRKSRC}/${MAN6} ${PREFIX}/man/man6/
.if	!defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/nonsense
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nonsense/
.endif

.include <bsd.port.mk>
