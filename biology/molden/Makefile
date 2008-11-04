# New ports collection makefile for:	molden
# Date created:		1998-11-14
# Whom:			rmiya
#
# $FreeBSD$
#

PORTNAME=	molden
PORTVERSION=	4.7
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.cmbi.kun.nl/pub/molgraph/molden/
DISTNAME=	${PORTNAME}${PORTVERSION}
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	oivulf@gmail.com
COMMENT=	Display molecular orbitals and electron densities in 2D and 3D

USE_XORG=	x11 xmu
USE_GL=		glut
USE_FORTRAN=	yes

RESTRICTED=	free for academic, non profit usage; do not re-distribute source and executable.
MAKEFILE=	${WRKSRC}/makefile

post-patch:
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' ${WRKSRC}/xwin.c

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
	${MKDIR} ${PREFIX}/share/doc/molden
	${MKDIR} ${PREFIX}/share/molden/test
	${MKDIR} ${PREFIX}/share/molden/utils
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/molden
	${INSTALL_DATA} ${WRKSRC}/test/* ${PREFIX}/share/molden/test
	${INSTALL_DATA} ${WRKSRC}/utils/* ${PREFIX}/share/molden/utils
.endif

.include <bsd.port.mk>
