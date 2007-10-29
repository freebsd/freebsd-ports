# New ports collection makefile for:	fldigi
# Date created:				December 20 2006
# Whom:					Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	fldigi
PORTVERSION=	2.03
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/fldigi-2.0.distro/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Digital decoder for psk, cw, psk31, olivia

LIB_DEPENDS=	fltk:${PORTSDIR}/x11-toolkits/fltk-threads \
		hamlib:${PORTSDIR}/comms/hamlib \
		sndfile:${PORTSDIR}/audio/libsndfile \
		boost_wave:${PORTSDIR}/devel/boost

USE_GMAKE=	yes

MAKE_ENV+=	CXX="${CXX}"

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Install/fldigi ${PREFIX}/bin/fldigi
	${MKDIR} ${DATADIR}
.for f in ${WRKSRC}/icons/fldigi-psk.png \
	${WRKSRC}/icons/fldigi-rtty.png \
	${WRKSRC}/icons/fldigi.xpm
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
