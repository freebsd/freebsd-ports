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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A customizable IDE that supports a wide variety of languages

USE_QT_VER=	2
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_XLIB=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	QTDIR="${X11BASE}"
QTCPPFLAGS+=	-I${X11BASE}/include

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile"
.endif

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

pre-configure:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\$${prefix}/moonshine|$${prefix}/share/moonshine| ; \
		 s|@INSTBIN@|${PREFIX}/bin| ; s|moc -o|$$(MOC) -o|'
	@${REINPLACE_CMD} -e 's|/usr/share/moonshine|${PREFIX}/share/moonshine|' \
		${WRKSRC}/include/tags.h

.include <bsd.port.post.mk>
