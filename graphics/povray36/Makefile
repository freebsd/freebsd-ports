# New ports collection makefile for:    POV-Ray
# Version required:     3.3
# Date created:         3 Dec 1996
# Whom:                 paulo@isr.uc.pt
#
# $Id: Makefile,v 1.10 1998/09/15 11:57:42 asami Exp $
#

DISTNAME=       povray3
PKGNAME=	povray-3.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://povray.cdrom.com/pub/povray/Official-3.0/Unix/ \
	 	ftp://www.hensa.ac.uk/mirrors/povray/povray/Official-3.0/Unix/\
		ftp://ftp.univ-lille1.fr/pub/povray/Official-3.0/Unix/
DISTFILES=      povuni_s.tgz povuni_d.tgz

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=    png.2:${PORTSDIR}/graphics/png

BROKEN=		checksum

MAN1=		povray.1

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
	@chmod -R og-r ${POVLIB}
	@chmod -R a+r ${POVLIB}

.include <bsd.port.mk>
