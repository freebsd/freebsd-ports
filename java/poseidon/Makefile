# Ports collection makefile for:	Poseidon
# Date created:			February 28, 2004
# Whom:				gerrit@beine-computer.de
#
# $FreeBSD$
#

PORTNAME=	poseidonCE
PORTVERSION=	2.2.1
CATEGORIES=	java
MASTER_SITES=	# http://www.gentleware.com/products/download.php4
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}	# Required to print the message

MAINTAINER=	gerrit@beine-computer.de
COMMENT=	A popular UML CASE tool

USE_ZIP=	yes
USE_JAVA=	1.4+
USE_REINPLACE=	yes
NO_BUILD=	yes
NO_PACKAGE=	"Redistribution is not permitted"
NO_CDROM=	${NO_PACKAGE}
RESTRICTED=	${NO_PACKAGE}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTFILES})
ECHO_MSG=/usr/bin/printf
IGNORE=	:\n\
Because of licensing restrictions, you must fetch the source distribution\n\
manually. Please access http://www.gentleware.com/products/download.php4\n\
with a web browser and load the \"ZIP for any Platform\" of the\n\
Community Edition.\n\
After download the file, place it into ${DISTDIR}.\n
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,%%JAVA_HOME%%,${JAVA_HOME}," ${WRKSRC}/bin/poseidon.sh

do-install:
	@${MKDIR} ${DATADIR}/bin
	@${MKDIR} ${DATADIR}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/bin/poseidon.sh ${DATADIR}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/license-keys.txt ${DATADIR}
.if !defined(NOPORTDOCS)
	${CP} -r ${WRKSRC}/docs ${DATADIR}
	${CP} -r ${WRKSRC}/examples ${DATADIR}
.endif

post-install:
	${LN} -s ${DATADIR}/bin/poseidon.sh ${LOCALBASE}/bin/poseidon

.include <bsd.port.post.mk>
