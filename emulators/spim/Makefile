# ex:ts=8
# Ports collection makefile for:  spim
# Date created:			  Mon Oct 28, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	spim
PORTVERSION=	6.3
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.cs.wisc.edu/pub/spim/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PREFIX?=	${LOCALBASE}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
USE_IMAKE=	yes
ALL_TARGET=	y.tab.c spim xspim
MAN1=		spim.1 xspim.1

pre-build:
	@${RM} -f ${WRKSRC}/y.tab.*

pre-install:
	@${MKDIR} ${PREFIX}/share/spim && ${CHMOD} a+rx,u+w ${PREFIX}/share/spim

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "Installing spim/xspim documentation"
	@${MKDIR} ${PREFIX}/share/doc/spim  \
		&& ${CHMOD} a+rx,u+w ${PREFIX}/share/doc/spim
	${INSTALL_DATA} ${WRKSRC}/Documentation/spim.ps  \
		${PREFIX}/share/doc/spim
	${INSTALL_DATA} ${WRKSRC}/Documentation/cycle.ps  \
		${PREFIX}/share/doc/spim
	${GZIP_CMD} ${PREFIX}/share/doc/spim/*.ps
.endif

.include <bsd.port.mk>
