# New ports collection makefile for:    hatari
# Date created:         15 March 2004
# Whom:                 Michael Neumann <mneumann@ntecs.de>
#
# $FreeBSD$
#

PORTNAME=	hatari
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Atari ST emulator

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MANLANG=	"" fr
MAN1=		${PORTNAME}.1

CPPFLAGS=	`libpng-config --I_opts`
LDFLAGS=	`libpng-config --L_opts`

post-patch:
	@${REINPLACE_CMD} -e '/if test/s|==|=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^ICONPATH/s|/icons/.*$$|/pixmaps|' \
		${WRKSRC}/python-ui/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${MANPREFIX}/man/fr/man1
	${INSTALL_MAN} ${WRKSRC}/doc/fr/${PORTNAME}.1 ${MANPREFIX}/man/fr/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/fr
	${INSTALL_DATA} ${WRKSRC}/doc/fr/*.txt ${DOCSDIR}/fr
	@${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/images/*.png ${DOCSDIR}/images
.endif

.include <bsd.port.mk>
