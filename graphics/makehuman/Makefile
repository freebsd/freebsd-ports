# New ports collection makefile for:	makehuman
# Date created:		06 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	makehuman
DISTVERSION=	0.8_beta
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Application for parametrical modeling of 3D humanoid characters

LIB_DEPENDS=	glpng:${PORTSDIR}/graphics/glpng \
		glut.4:${PORTSDIR}/graphics/libglut

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_X_PREFIX=	yes

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

post-patch:
	@${REINPLACE_CMD} -e 's|linux/||' ${WRKSRC}/src/io.h
	@${REINPLACE_CMD} -e '/^packagedocdir=/ s|doc|share/doc|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^makehumandocdir/ s|/doc/makehuman|/share/doc/makehuman|' ${WRKSRC}/Makefile.in

.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-makehumandocDATA||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
