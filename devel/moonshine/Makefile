# New ports collection makefile for:	moonshine
# Date created:		26 April 2000
# Whom:			Maxim Sobolev <sobomax@altavista.net>
#
# $FreeBSD$
#

PORTNAME=	moonshine
PORTVERSION=	1.1.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.suite3220.com/pub/Moonshine/1.1/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	sobomax@altavista.net

USE_QT2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${X11BASE}/include

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

pre-configure:
		@ find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
			's|\$$\{prefix\}/moonshine|\$$\{prefix\}/share/moonshine| ; \
			 s|\@INSTBIN\@|${PREFIX}/bin| ; s|moc -o|\$$\(MOC\) -o|'
		@ ${PERL} -pi -e 's|/usr/share/moonshine|${PREFIX}/share/moonshine|' \
			${WRKSRC}/include/tags.h

.include <bsd.port.mk>
