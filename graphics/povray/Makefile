# New ports collection makefile for:    POV-Ray
# Version required:     3.0.1
# Date created:         3 Dec 1996
# Whom:                 paulo@isr.uc.pt
#
# $FreeBSD$
#

DISTNAME=	povray3
PKGNAME=	povray-3.0.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.povray.org/pub/povray/Old-Versions/Official-3.0/Unix/ \
		ftp://www.hensa.ac.uk/mirrors/povray/Old-Versions/Official-3.0/Unix/\
		ftp://ftp.fh-aachen.de/pub/Graphics/mirror/ftp.povray.org/povray/Old-Versions/Official-3.0/Unix/ \
		ftp://ftp.kappa.ro/pub/Linux/Graphics/Editors/povray/
DISTFILES=	povuni_s.tgz povuni_d.tgz

MAINTAINER=	kris@FreeBSD.org

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png

DIST_SUBDIR=	povray30

USE_XLIB=	yes
MAN1=		povray.1
NO_LATEST_LINK=	yes

POVLIB=		${PREFIX}/lib/povray3

do-build:
	(cd ${WRKSRC}/source/unix; make newxwin)

do-install:
	@${MKDIR} ${POVLIB}/allscene
	@${INSTALL_PROGRAM} ${WRKSRC}/source/unix/x-povray ${PREFIX}/bin/povray
	@(cd ${WRKSRC}; tar cpf - pov3demo povscn docsdemo include texsamps) | \
		(cd ${POVLIB}; tar xpf -)
	@${INSTALL_DATA} ${WRKSRC}/*.ini ${POVLIB}/
	@${INSTALL_DATA} ${WRKSRC}/*.doc ${POVLIB}/
	@${INSTALL_DATA} ${WRKSRC}/*.gif ${WRKSRC}/*.xpm ${POVLIB}/
	@${INSTALL_SCRIPT} ${WRKSRC}/allscene.sh ${POVLIB}/
	@${RM} -f ${PREFIX}/man/man1/povray.1*
	@${INSTALL_MAN} ${WRKSRC}/povray.1 ${PREFIX}/man/man1
	@${CHMOD} -R og-r ${POVLIB}
	@${CHMOD} -R a+r ${POVLIB}

.include <bsd.port.mk>
