# New ports collection makefile for:	vtcl
# Date Created:		29 May 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	vtcl
PORTVERSION=	1.6.0b1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Application Development Environment For the TCL/TK language

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

HAS_CONFIGURE=	yes
NO_BUILD=	yes

pre-configure:
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/configure

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vtcl ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/vtcl
.for data in ChangeLog LICENSE README vtcl.tcl vtsetup.tcl
	${INSTALL_DATA} ${WRKSRC}/${data} ${PREFIX}/lib/vtcl
.endfor
	@${MKDIR} ${PREFIX}/lib/vtcl/images
.for sufx in gif ppm xbm xpm
	${INSTALL_DATA} ${WRKSRC}/images/*.${sufx} ${PREFIX}/lib/vtcl/images
.endfor
	@${MKDIR} ${PREFIX}/lib/vtcl/images/edit
	${INSTALL_DATA} ${WRKSRC}/images/edit/*.gif ${PREFIX}/lib/vtcl/images/edit
	@${MKDIR} ${PREFIX}/lib/vtcl/lib
	${CP} -r ${WRKSRC}/lib/* ${PREFIX}/lib/vtcl/lib
	@${MKDIR} ${PREFIX}/share/doc/vtcl
	${INSTALL_DATA} ${WRKSRC}/doc/tutorial.txt ${PREFIX}/share/doc/vtcl

.include <bsd.port.mk>
