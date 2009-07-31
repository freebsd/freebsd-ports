# New ports collection makefile for:	FreeDoko
# Date created:		02 Jun 2004
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freedoko
PORTVERSION=	0.7.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/free-doko
DISTNAME=	FreeDoko_${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Play the card game Doppelkopf

LIB_DEPENDS=	gnet-2.0.0:${PORTSDIR}/net/gnet2 \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

WRKSRC=		${WRKDIR}/${DISTNAME:C/\.src$//}/src

USE_ZIP=	yes
USE_GMAKE=	yes
MAKE_ENV=	OS="${OPSYS}" DATADIR="${DATADIR}"

post-patch:
	@${FIND} ${WRKSRC} -name "*Makefile*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\.\./data|$$(DATADIR)|g ; \
		 s|@echo $$(CXX)|@true $$(CXX)|g ; \
		 s|@$$(CXX)|$$(CXX)|g ; \
		 s|make -C|$$(MAKE) -C|g'
	@${RM} -rf ${WRKSRC}/../data/translations/fr/bak

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/FreeDoko ${PREFIX}/bin
	${LN} -sf FreeDoko ${PREFIX}/bin/freedoko
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/icon.png ${WRKSRC}/logo.png ${DATADIR}
.for dir in backgrounds cardsets rules translations
	@cd ${WRKSRC}/../data && ${FIND} ${dir} ! -name "*Makefile*" | \
		${CPIO} --quiet -pdum -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/../doc && ${FIND} . ! -name "*Makefile*" | \
		${CPIO} --quiet -pdum -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
