# New ports collection makefile for:	hawkvoice
# Date created:		2006-03-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	hawkvoice
PORTVERSION=	0.91
CATEGORIES=	audio devel
MASTER_SITES=	http://www.hawksoft.com/download/files/
DISTNAME=	HawkVoiceDI091src

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Portable sound and speech compression library

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile.linux
USE_LDCONFIG=	yes

LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS=	-I${LOCALBASE}/include
MAKE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}" \
		MAKE="${GMAKE}"

WRKSRC=	${WRKDIR}/HawkVoiceDI/src

OPTIONS=	OPTIMIZATION	"Enable optimization"	off

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC -DPIC
.endif

.if defined(WITH_OPTIMIZATION)
CFLAGS+=	-funroll-all-loops -ffast-math -fomit-frame-pointer -D_GNU_SOURCE -D_REENTRANT
.endif

post-patch:
	${FIND} ${WRKSRC} -type f -exec ${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' "{}" \;

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in api.txt HVDIchanges.txt readme.txt cryptapi.txt
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
