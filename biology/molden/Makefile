# New ports collection makefile for:	molden
# Date created:		1998-11-14
# Whom:			rmiya
#
# $FreeBSD$
#

PORTNAME=	molden
PORTVERSION=	4.6
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.cmbi.ru.nl/pub/molgraph/molden/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	oivulf@gmail.com
COMMENT=	Display molecular orbitals and electron densities in 2D and 3D

USE_XORG=	x11 xmu
USE_GL=		glut
USE_FORTRAN=	yes

RESTRICTED=	free for academic, non profit usage; do not re-distribute source and executable.
MAKEFILE=	${WRKSRC}/makefile

.if !defined(NOPORTDOCS)
PORTDOCS=	docs/*
.endif

post-configure:
	@${ECHO_MSG} "********************"
	@${ECHO_MSG} "**  If you want to use a larger MOLDEN,"
	@${ECHO_MSG} "**  edit change_parameter.sh and run it,"
	@${ECHO_MSG} "**  before \'make build\'."
	@${ECHO_MSG} "********************"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/molden ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ambfor/ambfor ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gmolden ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/surf/surf ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}/test
	${MKDIR} ${DATADIR}/utils
	${INSTALL_DATA} ${WRKSRC}/test/* ${DATADIR}/test
	${INSTALL_DATA} ${WRKSRC}/utils/* ${DATADIR}/utils
.endif

.include <bsd.port.mk>
