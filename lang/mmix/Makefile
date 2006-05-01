# Ports collection makefile for:	mmix
# Date created:				25 Oct 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mmix
PORTVERSION=	20060324
CATEGORIES=	lang
MASTER_SITES=	http://www-cs-faculty.stanford.edu/~knuth/programs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A RISC computer designed by Donald E. Knuth

BUILD_DEPENDS=	ctangle:${PORTSDIR}/devel/cweb

NO_WRKSUBDIR=	yes
FILES=		mmix.1 mmix.mp silly.out silly.run

post-patch:
	@${REINPLACE_CMD} -e "s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mmix ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mmixal ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mmmix ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mmotype ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.mmconfig ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.mmix ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.mms ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.w ${DATADIR}
.for f in ${FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor

.include <bsd.port.mk>
