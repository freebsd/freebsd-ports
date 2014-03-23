# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	secretmaryochronicles
PORTVERSION=	1.10.git20120512
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
#		SF/smclone/Secret%20Maryo%20Chronicles/${PORTVERSION}
DISTNAME=	smc-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Secret Maryo Chronicles two-dimensional platform game

BROKEN=		Does not compile with graphics/cegui 0.8.3.

LIB_DEPENDS=	libCEGUIBase-0.so:${PORTSDIR}/graphics/cegui \
		libboost_filesystem.so:${PORTSDIR}/devel/boost-libs \
		libpng15.so:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_AUTOTOOLS=	aclocal:env autoheader:env autoconf:env automake:env
GNU_CONFIGURE=	yes
USE_SDL=	sdl image mixer ttf
USE_GL=		gl glu
USES=		gettext gmake pkgconfig

CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-DBOOST_FILESYSTEM_VERSION=3
LDFLAGS+=	-L${LOCALBASE}/lib

DATADIR=	${PREFIX}/share/smc

WRKSRC=		${WRKDIR}/smc

PORTDOCS=	controls.html history.html style.css

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/autogen.sh

run-autotools:
	cd ${WRKSRC} && ${SH} ./autogen.sh
	@${REINPLACE_CMD} -e '/^LIBS =/ s|$$|$$(INTLLIBS)|' \
		${WRKSRC}/src/Makefile.in

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
