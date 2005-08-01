# New ports collection makefile for:	FreeDoko
# Date created:		02 Jun 2004
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freedoko
PORTVERSION=	0.6.9
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	free-doko
DISTNAME=	FreeDoko_${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Play the card game Doppelkopf

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

WRKSRC=		${WRKDIR}/${DISTNAME:C/\.src$//}/src

USE_ZIP=	yes
USE_GCC=	3.4+
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ENV=	OSTYPE=linux-gnu DATADIR=${DATADIR}

post-patch:
	@${FIND} ${WRKSRC} -name "*Makefile*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\.\./data|$$(DATADIR)|g ; \
		 s|gtkmm-2.0|gtkmm-2.4|g ; \
		 s|@echo $$(CXX)|@true $(CXX)|g ; \
		 s|@$$(CXX)|$$(CXX)|g ; \
		 s|make -C|$$(MAKE) -C|g'
	@${REINPLACE_CMD} -e \
		's|SigC::slot|sigc::ptr_fun|g' ${WRKSRC}/ui/gtkmm/utils.cpp
	@${FIND} ${WRKSRC}/ui/gtkmm -name "*.cpp" -or -name "*.h" | \
		${XARGS} ${REINPLACE_CMD} -e \
		's|SigC::Object|sigc::trackable|g ; \
		 s|SigC::slot|sigc::mem_fun|g ; \
		 s|SigC::Connection|sigc::connection|g ; \
		 s|SigC::Slot|sigc::slot|g ; \
		 s|SigC|sigc|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/FreeDoko ${PREFIX}/bin
	${LN} -sf FreeDoko ${PREFIX}/bin/freedoko
	@${MKDIR} ${DATADIR}
.for dir in ai backgrounds cardsets rules translations
	@cd ${WRKSRC}/../data && ${FIND} ${dir} ! -name "*Makefile*" | \
		${CPIO} --quiet -pdum -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/../doc && ${FIND} . ! -name "*Makefile*" | \
		${CPIO} --quiet -pdum -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
