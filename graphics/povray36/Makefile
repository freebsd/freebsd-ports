# New ports collection makefile for:    POV-Ray
# Date created:         3 Dec 1996
# Whom:                 paulo@isr.uc.pt
#
# $FreeBSD$
#

PORTNAME=	povray
PORTVERSION=	3.0.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.povray.org/pub/povray/%SUBDIR%/ \
		ftp://ftp.gigabell.net/pub/unix/apps/graphics/povray/%SUBDIR%/ \
		ftp://www.hensa.ac.uk/mirrors/povray/%SUBDIR%/ \
		ftp://ftp.fh-aachen.de/pub/mirror/ftp.povray.org/povray/%SUBDIR%/
MASTER_SITE_SUBDIR=	Old-Versions/Official-3.0/Unix
DISTNAME=	povray3
DISTFILES=	povuni_s.tgz povuni_d.tgz
DIST_SUBDIR=	povray30

MAINTAINER=	kris@FreeBSD.org

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png

USE_XLIB=	yes
MAN1=		povray.1
NO_LATEST_LINK=	yes

POVLIB=		${PREFIX}/lib/povray3

do-build:
	(cd ${WRKSRC}/source/unix; ${SETENV} ${MAKE_ENV} ${MAKE} newxwin)

do-install:
	@${MKDIR} ${POVLIB}/allscene
	@${INSTALL_PROGRAM} ${WRKSRC}/source/unix/x-povray ${PREFIX}/bin/povray
	@(cd ${WRKSRC}; ${TAR} cpf - pov3demo povscn docsdemo include texsamps) | \
		(cd ${POVLIB}; ${TAR} xpf -)
	@${INSTALL_DATA} ${WRKSRC}/*.ini ${POVLIB}/
	@${INSTALL_DATA} ${WRKSRC}/*.doc ${POVLIB}/
	@${INSTALL_DATA} ${WRKSRC}/*.gif ${WRKSRC}/*.xpm ${POVLIB}/
	@${INSTALL_SCRIPT} ${WRKSRC}/allscene.sh ${POVLIB}/
	@${RM} -f ${PREFIX}/man/man1/povray.1*
	@${INSTALL_MAN} ${WRKSRC}/povray.1 ${PREFIX}/man/man1
	@${CHMOD} -R og-r ${POVLIB}
	@${CHMOD} -R a+r ${POVLIB}

.include <bsd.port.mk>
