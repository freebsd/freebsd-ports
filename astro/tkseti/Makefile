# Ports collection makefile for:	tkseti
# Date created:		30 Jun 1999
# Whom:			Brett Taylor <brett@peloton.physics.montana.edu>
#
# $FreeBSD$
#

PORTNAME=	tkseti
PORTVERSION=	3.10.2
CATEGORIES=	astro tk84
MASTER_SITES=	http://norlug.org/~chipster/resources/tkseti/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tk-based interface to SETI@Home

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		${LOCALBASE}/sbin/setiathome:${PORTSDIR}/astro/setiathome

USE_REINPLACE=	yes
NO_BUILD=	yes

MAN1=		tkseti.1
PORTDOCS=	DOC README
PLIST_FILES=	bin/tkseti

WISH=		${LOCALBASE}/bin/wish8.4

post-patch:
	@${REINPLACE_CMD} -e 's|%%WISH%%|${WISH}|g' ${WRKSRC}/tkseti
	@cd ${WRKSRC}/man && ${BZIP2_CMD} -d tkseti.1.bz2

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkseti ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/tkseti.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/docs/DOC ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
