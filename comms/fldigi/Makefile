# New ports collection makefile for:	fldigi
# Date created:				December 20 2006
# Whom:					Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	fldigi
PORTVERSION=	1.23
DISTVERSIONSUFFIX=	.src
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/LinuxApps/ \
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
	${INSTALL_PROGRAM} ${WRKSRC}/fldigi ${PREFIX}/bin/fldigi
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/macros.mdf ${DATADIR}
.if	!defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${ECHO} ""
	@${ECHO} "fldigi docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
