# New ports collection makefile for:	fldigi
# Date created:				December 20 2006
# Whom:					Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	fldigi
PORTVERSION=	1.342
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/fldigi.1.34.distro/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Digital decoder for psk, cw, psk31, olivia

LIB_DEPENDS=	fltk:${PORTSDIR}/x11-toolkits/fltk-threads \
		hamlib:${PORTSDIR}/comms/hamlib

USE_GMAKE=	yes
ALL_TARGET=	fldigi
MAKEFILE=	makefile

MAKE_ENV+=	CXX="${CXX}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Install/fldigi ${PREFIX}/bin/fldigi
	${MKDIR} ${DATADIR}
.for f in ${WRKSRC}/Install/fldigi-psk.png \
	${WRKSRC}/Install/fldigi-rtty.png \
	${WRKSRC}/Install/fldigi.xpm 
	${INSTALL_DATA} ${WRKSRC}$f ${DATADIR} 
.endfor
	@${ECHO} ""
.if	!defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${ECHO} "fldigi docs installed in ${DOCSDIR}"
.endif
	@${ECHO} "fldigi icons installed in ${DATADIR}"
	@${ECHO} ""

.include <bsd.port.mk>
