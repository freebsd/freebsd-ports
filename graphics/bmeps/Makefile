# New ports collection makefile for:	bmeps
# Date created:				6 Jan 2004
# Whom:					Hideyuki KURASHINA <rushani@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmeps
PORTVERSION=	2.1.5
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Convert bitmap images (PNG/JPEG/NetPBM) to EPS

LIB_DEPENDS=	dkbif.1:${PORTSDIR}/devel/dklibs

MAKE_JOBS_SAFE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include"
GNU_CONFIGURE=	yes
MAKE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	bmeps.1
.endif

post-install:
.if !defined(NO_INSTALL_MANPAGES)
	${MKDIR} ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}.1 ${MANPREFIX}/man/man1
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/*.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/*.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/*.png ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
