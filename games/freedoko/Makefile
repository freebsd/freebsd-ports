# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freedoko
PORTVERSION=	0.7.11
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/free-doko/FreeDoko%20source
DISTNAME=	FreeDoko_${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Play the card game Doppelkopf

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	gnet-2.0.0:${PORTSDIR}/net/gnet2 \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

WRKSRC=		${WRKDIR}/${DISTNAME:C/\.src$//}/src

USE_ZIP=	yes
USES=		gmake pkgconfig
MAKE_ENV=	OS="${OPSYS}" DATADIR="${DATADIR}" DOCSDIR="${DOCSDIR}"

NO_STAGE=	yes
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
	${INSTALL_PROGRAM} ${WRKSRC}/FreeDoko ${PREFIX}/bin
	${LN} -sf FreeDoko ${PREFIX}/bin/freedoko
	@${MKDIR} ${DATADIR}
.for file in icon.png logo.png
	${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}
.endfor
.for dir in backgrounds cardsets rules translations
	@cd ${WRKSRC}/../data && ${FIND} ${dir} ! -name "*Makefile*" | \
		${CPIO} --quiet -pdum -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/../doc/manual && ${FIND} . | \
		${CPIO} --quiet -pdum -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
