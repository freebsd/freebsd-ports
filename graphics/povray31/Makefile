# New ports collection makefile for:    POV-Ray
# Date created:         3 Dec 1996
# Whom:                 paulo@isr.uc.pt
#
# $FreeBSD$
#

PORTNAME=	povray
PORTVERSION=	3.1g
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.povray.org/pub/povray/%SUBDIR%/ \
		ftp://ftp.gigabell.net/pub/unix/apps/graphics/povray/%SUBDIR%/ \
		ftp://www.hensa.ac.uk/mirrors/povray/%SUBDIR%/ \
		ftp://ftp.fh-aachen.de/pub/mirror/ftp.povray.org/povray/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/povray/%SUBDIR%,}
MASTER_SITE_SUBDIR=	Old-Versions/Official-3.1g/Unix
DISTNAME=	povray31
DISTFILES=	povuni_s.tgz povuni_d.tgz

MAINTAINER=	olli@fromme.com
COMMENT=	Persistence of Vision Ray Tracer

#BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

DIST_SUBDIR=	povray31

#
#   I think all of this needs some explanation.
#   The port downloads the MS-DOS source files of POV-Ray 3.1d
#   and the UNIX source files of POV-Ray 3.0 (which need some
#   patching, obviously).  This is necessary because there are
#   no UNIX source files for POV-Ray 3.1.
#

USE_XLIB=	yes
MAN1=		povray.1

POVLIB=		${PREFIX}/lib/povray31

do-build:
	@(cd ${WRKSRC}/source/unix; ${SETENV} ${MAKE_ENV} ${MAKE} newxwin)

do-install:
	@${MKDIR} ${POVLIB}/allscene
	@${TOUCH} ${POVLIB}/allscene/.bla
	@${INSTALL_PROGRAM} ${WRKSRC}/source/unix/x-povray ${PREFIX}/bin/povray
	@(cd ${WRKSRC}; ${TAR} cpf - include scenes) | \
		(cd ${POVLIB}; ${TAR} xpf -)
	@${INSTALL_DATA} ${WRKSRC}/*.ini ${POVLIB}/
	@${INSTALL_DATA} ${WRKSRC}/*.doc ${POVLIB}/
	@${INSTALL_DATA} ${WRKSRC}/*.txt ${POVLIB}/
	@${INSTALL_DATA} ${WRKSRC}/*.gif ${WRKSRC}/*.xpm ${POVLIB}/
	@${INSTALL_SCRIPT} ${WRKSRC}/allscene.sh ${POVLIB}/
	@${RM} -f ${PREFIX}/man/man1/povray.1*
	@${INSTALL_MAN} ${WRKSRC}/povray.1 ${PREFIX}/man/man1
	@${CHMOD} -R a+rX,og-w ${POVLIB}

post-install:
	@${SH} ${FILESDIR}/script

.include <bsd.port.mk>
