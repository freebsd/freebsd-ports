# New ports collection makefile for:    jedit-devel
# Date created:				02 Feb 2004
# Whom:					Linh Pham <question+fbsdports@closedsrc.org>
#
# $FreeBSD$
#

PORTNAME=	jedit
PORTVERSION=	4.2.0pre13
CATEGORIES=	editors java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
_DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}install
DISTNAME=	${_DISTNAME:S/0pre/pre/}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful programmer's text editor written in Java

USE_JAVA=	1.3+

USE_XLIB=	yes
NO_BUILD=	yes

MAN1=		jedit.1
# The complete PLIST is generated in post-install
PLIST_FILES=	bin/jedit

do-configure:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g ; s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${FILESDIR}/jedit.sh > ${WRKDIR}/jedit.sh

do-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}| ; s|%%WRKDIR%%|${WRKDIR}|" ${FILESDIR}/instscript | \
		${SETENV} CLASSPATH=${DISTDIR}/${DISTNAME}.jar \
		${LOCALBASE}/bin/javavm installer.Install text
	@${INSTALL_SCRIPT} ${WRKDIR}/jedit.sh ${PREFIX}/bin/jedit

.if defined(PARALLEL_PACKAGE_BUILD)
IGNORE=	hang
.endif

post-install:
	@${FIND} ${JAVASHAREDIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${JAVASHAREDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${ECHO_CMD} "******************************************************"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "In order to use the optional SFTP plug-in for jEdit,"
	@${ECHO_CMD} "you will need to have Java JDK version 1.4 or newer"
	@${ECHO_CMD} "installed."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "******************************************************"

.include <bsd.port.mk>
