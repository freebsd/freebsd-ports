# New ports collection makefile for:	moonshine
# Date created:				26 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	moonshine
PORTVERSION=	1.1.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.suite3220.com/pub/Moonshine/1.1/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	sobomax@FreeBSD.org

USE_QT_VER=	2
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	QTDIR="${X11BASE}"
QTCPPFLAGS+=	-I${X11BASE}/include

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

pre-configure:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$$\{prefix\}/moonshine|\$$\{prefix\}/share/moonshine| ; \
		 s|\@INSTBIN\@|${PREFIX}/bin| ; s|moc -o|\$$\(MOC\) -o|'
	@${PERL} -pi -e 's|/usr/share/moonshine|${PREFIX}/share/moonshine|' \
		${WRKSRC}/include/tags.h

.include <bsd.port.post.mk>
