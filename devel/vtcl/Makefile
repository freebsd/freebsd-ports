# New ports collection makefile for:	vtcl
# Date Created:		29 May 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	vtcl
PORTVERSION=	1.2.0
CATEGORIES=	devel tk82
MASTER_SITES=	http://vtcl.sourceforge.net/dload/

MAINTAINER=	vanilla@FreeBSD.org

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/vt.tcl

do-install:
	@${MKDIR} ${PREFIX}/lib/vtcl/images
	@${MKDIR} ${PREFIX}/lib/vtcl/images/edit
	@${MKDIR} ${PREFIX}/lib/vtcl/lib
	@${MKDIR} ${PREFIX}/share/doc/vtcl
	${INSTALL_SCRIPT} ${WRKSRC}/vtcl ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/tutorial.txt ${PREFIX}/share/doc/vtcl
.for data in Announce ChangeLog README vt.tcl
	${INSTALL_DATA} ${WRKSRC}/${data} ${PREFIX}/lib/vtcl
.endfor
.for sufx in gif ppm xbm xpm
	${INSTALL_DATA} ${WRKSRC}/images/*.${sufx} ${PREFIX}/lib/vtcl/images
.endfor
	${INSTALL_DATA} ${WRKSRC}/images/edit/*.gif ${PREFIX}/lib/vtcl/images/edit
.for sufx in sh tcl
	${INSTALL_DATA} ${WRKSRC}/lib/*.${sufx} ${PREFIX}/lib/vtcl/lib
.endfor

.include <bsd.port.mk>
