# New ports collection makefile for:	radrails
# Date created:		2006-04-13
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	radrails
PORTVERSION=	0.7.2
CATEGORIES=	devel ruby java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux-gtk

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	IDE for Ruby On Rails

RUN_DEPENDS=	${LOCALBASE}/bin/rails:${PORTSDIR}/www/rubygem-rails

WRKSRC=		${WRKDIR}/${PORTNAME}

BROKEN=		does not build

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_LINUX_APPS=	gtk2
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	linux

ICONDIR=	icons
ICON=		${ICONDIR}/radrails.png

DESKTOP_ENTRIES=	\
	"RADRails" \
	"Integrated Developement Environment for Ruby On Rails" \
	"${DATADIR}/${ICON}" \
	"radrails" \
	"Development;IDE;" \
	true

PLIST_FILES=	%%DATADIR%%/${ICON} bin/radrails
PLIST_DIRS=	%%DATADIR%%/${ICONDIR}

pre-install:
	(cd ${WRKDIR}; jar -xf ${WRKSRC}/plugins/org.radrails.ide.ui_${PORTVERSION}.jar ${ICON})
	${CP} ${FILESDIR}/radrails.sh ${WRKDIR}/radrails.sh
	${REINPLACE_CMD} -E -e "s|%%DATADIR%%|${DATADIR}|g; s|%%JAVA%%|${JAVA}|g" ${WRKDIR}/radrails.sh
	${BRANDELF} -t 'Linux' ${WRKSRC}/RadRails

do-install:
	${MKDIR} ${DATADIR}
	( cd ${WRKSRC} \
	  && ${FIND} . -type d -exec ${MKDIR} ${DATADIR}/\{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${DATADIR}/\{} \; )
	${MKDIR} ${DATADIR}/${ICONDIR}
	${INSTALL_DATA} ${WRKDIR}/${ICON} ${DATADIR}/${ICON}
	${INSTALL_SCRIPT} ${WRKDIR}/radrails.sh ${PREFIX}/bin/radrails

post-install:
	@cd ${WRKSRC} \
	  && ${FIND} -s . -type f \
	    | ${SED} 's,^\.,${DATADIR:S,^${PREFIX}/,,},' >>${TMPPLIST} \
	  && ${FIND} -s -d . -type d \
	    | ${SED} 's,^\.,@dirrm ${DATADIR:S,^${PREFIX}/,,},' >>${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
