# New ports collection makefile for:	snowstar
# Date created:				21 April 1999
# Whom:					fenner
#
# $FreeBSD$

PORTNAME=	snowstar
PORTVERSION=	0.75.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner
EXTRACT_SUFX=	.tar

MAINTAINER=	fenner@FreeBSD.Org
COMMENT=	A GUI interface to copy files to/from the Diamond Rio PM300

RUN_DEPENDS=	rio:${PORTSDIR}/audio/rio \
		wish8.2:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=	true
NO_WRKSUBDIR=	true

DOC_FILES=	CHANGES TODO README_Snowstar LICENSE

# somehow snowstar.tcl managed to get loaded with ^M's.
post-patch:
	@${CP} ${WRKSRC}/snowstar.tcl ${WRKSRC}/snowstar.tcl.bak
	@${TR} -d '\r' < ${WRKSRC}/snowstar.tcl.bak | \
		sed -e "s|%%LOCALBASE%%|${LOCALBASE}|g" > ${WRKSRC}/snowstar.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/snowstar.tcl ${PREFIX}/bin/snowstar
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/snowstar
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/snowstar
.endfor
.endif

.include <bsd.port.mk>
