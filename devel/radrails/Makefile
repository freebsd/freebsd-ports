# New ports collection makefile for:	radrails
# Date created:		2006-04-13
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	radrails
PORTVERSION=	0.6.2
CATEGORIES=	devel ruby java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	IDE for Ruby On Rails

RUN_DEPENDS=	${LINUXBASE}/usr/bin/gtk-demo:${PORTSDIR}/x11-toolkits/linux-gtk2 \
		${LOCALBASE}/bin/rails:${PORTSDIR}/www/rubygem-rails

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	yes

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	linux
PLIST=		${WRKDIR}/PLIST

ICONDIR=	icons
ICON=		${ICONDIR}/radrails.png

DESKTOP_ENTRIES=	\
	"RADRails" \
	"Integrated Developement Environment for Ruby On Rails" \
	"${DATADIR}/${ICON}" \
	"radrails" \
	"Development;IDE;" \
	true

FIND_ARGS=	-s -d .

.include <bsd.port.pre.mk>

do-configure:

pre-install:
	(cd ${WRKDIR}; jar -xf ${WRKSRC}/plugins/org.radrails.ide.ui_${PORTVERSION}.jar ${ICON})
	${ECHO} "%%DATADIR%%/${ICON}" >> ${PLIST}
	${CP} ${FILESDIR}/radrails.sh ${WRKDIR}/radrails.sh
	${REINPLACE_CMD} -E -e "s|%%DATADIR%%|${DATADIR}|g; s|%%JAVA%%|${JAVA}|g" ${WRKDIR}/radrails.sh
	${ECHO} "bin/radrails" >> ${PLIST}
	( cd ${WRKSRC} ; \
	  ${FIND} ${FIND_ARGS} -type f | ${SED} 's|^|%%DATADIR%%/|g' >> ${PLIST} ; \
	  ${FIND} ${FIND_ARGS} -type d -and -not -name '.' | ${SED} 's|^|@dirrm %%DATADIR%%/|g' >> ${PLIST} )
	${ECHO} "@dirrm %%DATADIR%%/${ICONDIR}" >>${PLIST}
	${ECHO} '@dirrm %%DATADIR%%' >> ${PLIST}

do-install:
	${MKDIR} ${DATADIR}
	( cd ${WRKSRC} ; ${CP} -Rv `ls -a | ${EGREP} -v '^\.{1,2}$$'` ${DATADIR}/ )
	${MKDIR} ${DATADIR}/${ICONDIR}
	${INSTALL_DATA} ${WRKDIR}/${ICON} ${DATADIR}/${ICON}
	${INSTALL_SCRIPT} ${WRKDIR}/radrails.sh ${PREFIX}/bin/radrails

.include <bsd.port.post.mk>
