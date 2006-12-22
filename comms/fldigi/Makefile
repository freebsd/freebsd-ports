# New ports collection makefile for:	fldigi
# Date created:				December 20 2006
# Whom:					Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	fldigi
PORTVERSION=	1.11
DISTVERSIONSUFFIX=	.src
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/LinuxApps/

MAINTAINER=	db@db.net
COMMENT=	Digital decoder for psk, cw, psk31, olivia

LIB_DEPENDS=	fltk:${PORTSDIR}/x11-toolkits/fltk-threads \
		hamlib:${PORTSDIR}/comms/hamlib

USE_GMAKE=	yes
ALL_TARGET=	fldigi

MAKE_ENV+=	CXX="${CXX}"

post-extract:
	@${SED} -e 's|%%DATADIR%%|${DATADIR}|' \
		${FILESDIR}/${PORTNAME} > ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Release/${PORTNAME} \
		${PREFIX}/bin/${PORTNAME}.bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/macros.mdf ${DATADIR}
.if(!defined(NOPORTDOCS))
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
