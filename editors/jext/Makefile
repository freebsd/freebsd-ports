# New ports collection makefile for:    jext
# Date created:				17 Febrary 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jext
PORTVERSION=	3.0.2
PORTREVISION=	3
CATEGORIES=	editors java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jext

MAINTAINER=	vd@datamax.bg
COMMENT=	Powerful 100% pure Java text editor

USE_JAVA=	yes
JAVA_VERSION=	1.2+
NO_WRKSUBDIR=	yes
USE_XLIB=	yes
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	jext.sh

INSTALL_FILES=	Jython-LICENSE LICENSE README History.txt Names.txt bin lib

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/jext.sh ${PREFIX}/bin/jext
	${TAR} -C ${WRKSRC} -c -f - ${INSTALL_FILES} | ${TAR} -C ${DATADIR} --unlink -x -f -
	CLASSPATH=${DATADIR}/lib/jython.jar ${LOCALBASE}/bin/java org.python.util.jython \
		${DATADIR}/lib/Lib/compileall.py ${DATADIR}

post-install:
	@${FIND} ${DATADIR}/lib/cachedir -type f | ${SED} 's|^${PREFIX}/||' \
		| ${SORT} >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S|${PREFIX}/||}/lib/cachedir/packages' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S|${PREFIX}/||}/lib/cachedir' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S|${PREFIX}/||}/lib' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S|${PREFIX}/||}' >> ${TMPPLIST}

.include <bsd.port.mk>
