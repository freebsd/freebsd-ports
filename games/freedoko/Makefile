# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freedoko
PORTVERSION=	0.7.12
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/free-doko/FreeDoko%20source
DISTNAME=	FreeDoko_${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Play the card game Doppelkopf

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libgnet-2.0.so:${PORTSDIR}/net/gnet2

WRKSRC=		${WRKDIR}/${DISTNAME:C/\.src$//}/src

USES=		gmake pkgconfig zip:infozip
USE_GNOME=	gtkmm24
MAKE_ENV=	OS="${OPSYS}" DATADIR="${DATADIR}" DOCSDIR="${DOCSDIR}"

PLIST_FILES=	bin/FreeDoko bin/freedoko
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC} -name "*Makefile*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\.\./data|$$(DATADIR)|g ; \
		 s|\.\./doc/manual|$$(DOCSDIR)/manual|g ; \
		 s|@echo $$(CXX)|@true $$(CXX)|g ; \
		 s|@$$(CXX)|$$(CXX)|g ; \
		 s|make -C|$$(MAKE) -C|g'
	@${REINPLACE_CMD} -e '/\/X11\//d ; \
		 s|/usr/local/|${LOCALBASE}/|g' ${WRKSRC}/misc/setting.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/FreeDoko ${STAGEDIR}${PREFIX}/bin
	${LN} -sf FreeDoko ${STAGEDIR}${PREFIX}/bin/freedoko
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for file in icon.png logo.png
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DATADIR}
.endfor
.for dir in backgrounds cardsets rules translations
	cd ${WRKSRC}/../data && ${FIND} ${dir} ! -name "*Makefile*" | \
		${CPIO} --quiet -pdum ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/../doc/manual && ${FIND} . | \
		${CPIO} --quiet -pdum ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
