# New ports collection makefile for:	scm
# Date created:		Sat Nov  5 17:11:01 PST 1994
# Whom:			hsu
#
# $FreeBSD$
#

PORTNAME=	scm
PORTVERSION=	5d2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.swiss.ai.mit.edu/pub/scm/OLD/
MASTER_SITE_SUBDIR=	jacal
DISTFILES=	scm5d2.zip slib2c7.zip slib-psd1-3.tar.gz scmconfig4e3.tar.gz

MAINTAINER=	ports@FreeBSD.org

EXTRACT_ONLY=	scm5d2.zip slib2c7.zip

USE_ZIP=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/scm
MAN1=		scm.1

IMPLINIT=	${PREFIX}/libdata/scm/Init.scm

post-extract:
.for file in scmconfig4e3.tar.gz slib-psd1-3.tar.gz
	@${TAR} -C ${WRKDIR} -zxf ${_DISTDIR}/${file}
.endfor

post-configure:
	@${ECHO} '#ifndef IMPLINIT' > ${WRKSRC}/scmflags.h
	@${ECHO} '#define IMPLINIT "${IMPLINIT}"' >> ${WRKSRC}/scmflags.h
	@${ECHO} '#endif' >> ${WRKSRC}/scmflags.h

post-install:
	@touch ${PREFIX}/libdata/scm/implcat
	@touch ${PREFIX}/libdata/scm/slibcat
	@${MKDIR} ${PREFIX}/libdata/slib
	${INSTALL_DATA} ${WRKDIR}/slib/*.scm ${PREFIX}/libdata/slib
	@${MKDIR} ${PREFIX}/libdata/slib/psd
	${INSTALL_DATA} ${WRKDIR}/slib/psd/*.scm ${PREFIX}/libdata/slib/psd
	${INSTALL_DATA} ${WRKDIR}/scm/scm.info ${PREFIX}/info
	@install-info ${PREFIX}/info/scm.info ${PREFIX}/info/dir
	${INSTALL_DATA} ${WRKDIR}/slib/slib.info ${PREFIX}/info
	@install-info ${PREFIX}/info/slib.info ${PREFIX}/info/dir

.include <bsd.port.mk>
