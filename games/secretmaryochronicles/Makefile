# New ports collection makefile for:	secretmaryochronicles
# Date created:		31 Jan 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	secretmaryochronicles
PORTVERSION=	1.9
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/smclone/Secret%20Maryo%20Chronicles/${PORTVERSION}
DISTNAME=	smc-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Secret Maryo Chronicles two-dimensional platform game

BROKEN=		Does not work with CEGUI 0.7.x

LIB_DEPENDS=	CEGUIBase-0.7.5:${PORTSDIR}/graphics/cegui \
		boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		png.6:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl image mixer ttf
USE_GL=		gl glu
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"

DATADIR=	${PREFIX}/share/smc

post-patch:
	@${REINPLACE_CMD} -e '/^LIBS =/ s|$$|$$(INTLLIBS)|' \
		${WRKSRC}/src/Makefile.in

.if !defined(NOPORTDOCS)
PORTDOCS=	controls.html style.css

post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
