# New ports collection makefile for:   dosbox
# Date created:        28 July 2002
# Whom:                Tom Carrick <knyghtmare@knyghtmare.com>
#
# $FreeBSD$
#

PORTNAME=	dosbox
PORTVERSION=	0.73
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	knyght@gmail.com
COMMENT=	An emulator of a PC with DOS

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_SDL=	sdl net sound

MAN1=		dosbox.1
PKGMESSAGE=	${WRKDIR}/pkg-message

CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS+=	--enable-core-inline

post-patch:
	@${REINPLACE_CMD} -e 's#\/usr\/share\/doc\/dosbox#${DOCSDIR}#g' \
		${WRKSRC}/docs/dosbox.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dosbox ${PREFIX}/bin/dosbox
	${INSTALL_MAN} ${WRKSRC}/docs/dosbox.1 ${MAN1PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
.endif

.include <bsd.port.mk>
