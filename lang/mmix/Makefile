# Ports collection makefile for:	mmix
# Date created:				25 Oct 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mmix
PORTVERSION=	1.0
CATEGORIES=	lang
MASTER_SITES=	http://www-cs-faculty.stanford.edu/~knuth/programs/
DISTNAME=	mmix

MAINTAINER=	keith@FreeBSD.org

BUILD_DEPENDS=	ctangle:${PORTSDIR}/devel/cweb

MMIXDIR=	${PREFIX}/share/mmix
NO_WRKSUBDIR=	yes
FILES=		mmix.1 mmix.mp silly.out silly.run

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mmix ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mmixal ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mmotype ${PREFIX}/bin
	@${MKDIR} ${MMIXDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${MMIXDIR}
	${INSTALL_DATA} ${WRKSRC}/*.mmconfig ${MMIXDIR}
	${INSTALL_DATA} ${WRKSRC}/*.mmix ${MMIXDIR}
	${INSTALL_DATA} ${WRKSRC}/*.mms ${MMIXDIR}
	${INSTALL_DATA} ${WRKSRC}/*.w ${MMIXDIR}
.for f in ${FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${MMIXDIR}
.endfor

.include <bsd.port.mk>
