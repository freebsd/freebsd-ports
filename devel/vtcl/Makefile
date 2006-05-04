# New ports collection makefile for:	vtcl
# Date Created:		29 May 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	vtcl
PORTVERSION=	1.6.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mva@sysfault.org
COMMENT=	An Application Development Environment For the TCL/TK language

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

HAS_CONFIGURE=	yes
CONFIGURE_ARGS= ${PREFIX}
NO_BUILD=	yes

pre-configure:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/configure

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vtcl ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/vtcl
.for data in ChangeLog LICENSE README vtcl.tcl
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

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/* ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}/sample
	${CP} -r ${WRKSRC}/sample/* ${EXAMPLESDIR}/sample
		@${MKDIR} ${EXAMPLESDIR}/demo
	${CP} -r ${WRKSRC}/demo/* ${EXAMPLESDIR}/demo
.endif

.include <bsd.port.mk>
