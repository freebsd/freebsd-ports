# New ports collection makefile for:	when
# Date created:		1 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	when
PORTVERSION=	1.1.11
CATEGORIES=	deskutils
MASTER_SITES=	CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A very simple personal calendar

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

make-dist:
	@${RM} -rf ${WRKDIR};${MKDIR} ${WRKDIR};cd ${WRKDIR};\
	${FETCH_CMD} http://www.lightandmatter.com/when/when.tar.gz;\
	${TAR} xf when.tar.gz;${MV} when_dist ${DISTNAME};\
	${RM} -Rf ${DISTNAME}/debian_stuff/;\
	${TAR} cjvf ${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}

.include <bsd.port.mk>
