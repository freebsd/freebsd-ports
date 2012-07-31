# New ports collection makefile for:	gpscorrelate
# Date created:				Feb 2008
# Whom:					Lukas Maly
#
# $FreeBSD$

PORTNAME=	gpscorrelate
PORTVERSION=	1.5.6
PORTREVISION=	9
CATEGORIES=	astro geography
MASTER_SITES=	http://freefoote.dview.net/linux/

MAINTAINER=	Iam@LukasMaly.NET
COMMENT=	A gps file gpx correlate exif tag in photos

LIB_DEPENDS=	exiv2.12:${PORTSDIR}/graphics/exiv2 \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24

MAN1=		gpscorrelate.1 gpscorrelate-gui.1

post-patch:
	@${REINPLACE_CMD} -e "s|-I/usr/include|-I${LOCALBASE}/include|" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gpscorrelate ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gpscorrelate-gui ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/gpscorrelate* ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/gpscorrelate
	${MKDIR} ${PREFIX}/share/gpscorrelate
	${MKDIR} ${PREFIX}/share/doc/gpscorrelate/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/gpscorrelate/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${PREFIX}/share/doc/gpscorrelate/html
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/gpscorrelate/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/gpscorrelate/
	${INSTALL_DATA} ${WRKSRC}/RELEASES ${PREFIX}/share/gpscorrelate/

.include <bsd.port.mk>
