# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freedoko
PORTVERSION=	0.7.16
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/free-doko/FreeDoko%20source
DISTNAME=	FreeDoko_${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Play the card game Doppelkopf

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../doc/GPL

WRKSRC=		${WRKDIR}/${DISTNAME:C/\.src$//}/src

USES=		compiler:c++14-lang gmake pkgconfig zip:infozip
USE_CXXSTD=	c++14
USE_GNOME=	gdkpixbuf2 gtkmm30
LLD_UNSAFE=	yes
MAKE_ENV=	OS="${OPSYS}" DATADIR="${DATADIR}" DOCSDIR="${DOCSDIR}"

OPTIONS_DEFINE=		DOCS NETWORK OPENAL
OPTIONS_DEFAULT=	NETWORK OPENAL

NETWORK_DESC=		Network support
NETWORK_LIB_DEPENDS=	libgnet-2.0.so:net/gnet2
NETWORK_MAKE_ENV=	USE_NETWORK=true

OPENAL_USES=		openal:al,alut
OPENAL_MAKE_ENV=	INCLUDE_SOUND_ALUT="$$(pkg-config --cflags freealut)" \
			LIBS_SOUND_ALUT="$$(pkg-config --libs freealut)" \
			USE_SOUND=true USE_SOUND_ALUT=true

post-patch:
	@${REINPLACE_CMD} -e \
		's|@echo $$(CXX)|@true $$(CXX)|g ; \
		 s|@$$(CXX)|$$(CXX)|g' \
		${WRKSRC}/Makefile.rules
	@${REINPLACE_CMD} -e \
		'/\/X11\//d ; \
		 s|/usr/local/|${LOCALBASE}/|g' \
		${WRKSRC}/misc/setting.cpp
	@${REINPLACE_CMD} -e \
		'/^Exec/s|=.*|=FreeDoko| ; \
		 /^Path/d ; \
		 /Categories/s|Application;|GTK;|' \
		${WRKSRC}/../bin/FreeDoko.desktop

do-configure:
	@(cd ${WRKSRC} && ${SED} -e \
		'/VALUE/s|#CPPFLAGS|CPPFLAGS| ; \
		 s|\.\./data|$$(DATADIR)| ; \
		 s|\.\./manual|$$(DOCSDIR)/manual|' \
		< Makefile.local.template > Makefile.local)

post-build:
	@${FIND} ${WRKSRC}/../doc -empty -delete

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} FreeDoko \
		${STAGEDIR}${PREFIX}/bin)
	${LN} -sf FreeDoko ${STAGEDIR}${PREFIX}/bin/freedoko
	(cd ${WRKSRC}/../bin && ${INSTALL_DATA} FreeDoko.desktop \
		${STAGEDIR}${PREFIX}/share/applications)
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} icon.png logo.png \
		${STAGEDIR}${DATADIR})
.for i in backgrounds cardsets iconsets rules sounds translations
	(cd ${WRKSRC}/../data && ${COPYTREE_SHARE} ${i} \
		${STAGEDIR}${DATADIR} "! -name *Makefile*")
.endfor
	${RLN} ${STAGEDIR}${DATADIR}/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/FreeDoko.png

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/../doc && ${INSTALL_DATA} Bugs Roadmap \
		${STAGEDIR}${DOCSDIR})
	${MKDIR} ${STAGEDIR}${DOCSDIR}/de
	(cd ${WRKSRC}/../doc/de && ${INSTALL_DATA} LiesMich.* \
		${STAGEDIR}${DOCSDIR}/de)
	${MKDIR} ${STAGEDIR}${DOCSDIR}/en
	(cd ${WRKSRC}/../doc/en && ${INSTALL_DATA} README.* \
		${STAGEDIR}${DOCSDIR}/en)
	${MKDIR} ${STAGEDIR}${DOCSDIR}/manual
	(cd ${WRKSRC}/../manual && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR}/manual "! -name *Makefile*")

.include <bsd.port.mk>
