# New ports collection makefile for:	maven
# Date created:				17 October 2003
# Whom:					Rui Lopes <rui@ruilopes.com>
#
# $FreeBSD$
#

PORTNAME=	maven
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	${PORTNAME}/binaries

MAINTAINER=	jbq@caraldi.com
COMMENT=	Java project management and project comprehension tool

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_BZIP2=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
PKGMESSAGE=	${WRKDIR}/pkg-message
SUBSTITUTIONS=	-e 's,%%DATADIR%%,${DATADIR},g' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		-e 's,%%GREP%%,${GREP},g' \
		-e 's,%%CUT%%,${CUT},g'
REINPLACE_FILES=	${WRKSRC}/bin/maven

post-configure:
	@${SED} ${SUBSTITUTIONS} pkg-message > ${PKGMESSAGE}
	@${REINPLACE_CMD} ${SUBSTITUTIONS} ${REINPLACE_FILES}

BINFILES=	install_repo.sh maven
DIRECTORIES=	lib lib/endorsed plugins
do-install:
	${MKDIR} ${DATADIR}/bin
.for file in ${BINFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${file} ${DATADIR}/bin
.endfor
	${LN} -fs ${DATADIR}/bin/maven ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bin/forehead.conf ${DATADIR}/bin
	${INSTALL_DATA} ${WRKSRC}/*.xsd ${DATADIR}
.for dir in ${DIRECTORIES}
	${MKDIR} ${DATADIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.jar ${DATADIR}/${dir}
.endfor

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX}|${SED} -E 's,.*share/nls/.+$$,,g;s,${DATADIR:S,^${PREFIX}/,,},%%DATADIR%%,g'|${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.mk>
