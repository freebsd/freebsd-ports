# New ports collection makefile for:    POV-Ray
# Version required:     3.3
# Date created:         3 Dec 1996
# Whom:                 paulo@isr.uc.pt
#
# $Id$
#
DISTNAME=       povray3
PKGNAME=	povray-3.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://povray.cdrom.com/pub/povray/Official-3.0/Unix/ \
	 	ftp://www.hensa.ac.uk/mirrors/povray/povray/Official-3.0/Unix/\
		ftp://ftp.univ-lille1.fr/pub/povray/Official-3.0/Unix/
DISTFILES=      povuni_s.tgz povuni_d.tgz
MAN1=		povray.1
LIB_DEPENDS=	png:${PORTSDIR}/graphics/png \

do-build:
	(cd ${WRKSRC}/source/unix; make newxwin)

do-install:
	@${MKDIR} ${PREFIX}/man/man1; 
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/povray3; 
	@${MKDIR} ${PREFIX}/lib/povray3/allscene
	@${INSTALL} -c -m 755 ${WRKSRC}/source/unix/x-povray ${PREFIX}/bin/povray; 
	@cp -rp  ${WRKSRC}/pov3demo  ${PREFIX}/lib/povray3/pov3demo ;
	@cp -rp  ${WRKSRC}/docsdemo  ${PREFIX}/lib/povray3/docsdemo
	@cp -rp  ${WRKSRC}/include  ${PREFIX}/lib/povray3/include 
	@cp -rp  ${WRKSRC}/povscn  ${PREFIX}/lib/povray3/povscn
	@cp -rp  ${WRKSRC}/texsamps  ${PREFIX}/lib/povray3/texsamps
	@cp  ${WRKSRC}/*.ini   ${PREFIX}/lib/povray3/
	@cp  ${WRKSRC}/*.doc   ${PREFIX}/lib/povray3/
	@cp  ${WRKSRC}/*.gif  ${WRKSRC}/*.xpm   ${PREFIX}/lib/povray3/
	@install -c -m 755 ${WRKSRC}/allscene.sh ${PREFIX}/lib/povray3/
	@rm -f ${PREFIX}/man/man1/povray.1.gz
	@install -c -m 644 ${WRKSRC}/povray.1 ${PREFIX}/man/man1
	@chmod -R og-r   ${PREFIX}/lib/povray3
	@chmod -R a+r   ${PREFIX}/lib/povray3

.include <bsd.port.mk>
