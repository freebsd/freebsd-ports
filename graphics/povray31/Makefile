# New ports collection makefile for:    POV-Ray
# Version required:     3.1d
# Date created:         3 Dec 1996
# Whom:                 paulo@isr.uc.pt
#
# $Id: Makefile,v 1.1.1.1 1999/03/20 14:53:01 dburr Exp $
#

DISTNAME=	povray3
PKGNAME=	povray-3.1e
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.povray.org/pub/povray/Official/MS-Dos/ \
		ftp://ftp.povray.org/pub/povray/Old-Versions/Official-3.0/Unix/ \
		ftp://www.hensa.ac.uk/mirrors/povray/Official/MS-Dos/ \
		ftp://www.hensa.ac.uk/mirrors/povray/Old-Versions/Official-3.0/Unix/ \
		ftp://ftp.fh-aachen.de/pub/mirror/ftp.povray.org/povray/Official/MS-Dos/ \
		ftp://ftp.fh-aachen.de/pub/mirror/ftp.povray.org/povray/Old-Versions/Official-3.0/Unix/
DISTFILES=	povmsd_s.zip povuni_s.tgz povuni_d.tgz

MAINTAINER=	olli@fromme.com

BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png

#
#   I think all of this needs some explanation.
#   The port downloads the MS-DOS source files of POV-Ray 3.1d
#   and the UNIX source files of POV-Ray 3.0 (which need some
#   patching, obviously).  This is necessary because there are
#   no UNIX source files for POV-Ray 3.1.
#

USE_XLIB=	yes
MAN1=		povray.1

POVLIB=		${PREFIX}/lib/povray3

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@( \
		cd ${WRKDIR}; \
		${GUNZIP_CMD} -dcq ${DISTDIR}/povuni_s.tgz | tar xf -; \
		${GUNZIP_CMD} -dcq ${DISTDIR}/povuni_d.tgz | tar xf -; \
		cd ${DISTNAME}; \
		unzip -aqoL ${DISTDIR}/povmsd_s.zip \
	)

do-build:
	@(cd ${WRKSRC}/source/unix; make newxwin)

do-install:
	@${MKDIR} ${POVLIB}/allscene
	@${TOUCH} ${POVLIB}/allscene/.bla
	@${INSTALL_PROGRAM} ${WRKSRC}/source/unix/x-povray ${PREFIX}/bin/povray
	@(cd ${WRKSRC}; tar cpf - pov3demo povscn docsdemo include texsamps) | \
		(cd ${POVLIB}; tar xpf -)
	@${INSTALL_DATA} ${WRKSRC}/*.ini ${POVLIB}/
	@${INSTALL_DATA} ${WRKSRC}/*.doc ${POVLIB}/
	@${INSTALL_DATA} ${WRKSRC}/*.gif ${WRKSRC}/*.xpm ${POVLIB}/
	@${INSTALL_SCRIPT} ${WRKSRC}/allscene.sh ${POVLIB}/
	@${RM} -f ${PREFIX}/man/man1/povray.1*
	@${INSTALL_MAN} ${WRKSRC}/povray.1 ${PREFIX}/man/man1
	@chmod -R a+rX,og-w ${POVLIB}

.include <bsd.port.mk>
