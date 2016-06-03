# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	hawkvoice
PORTVERSION=	0.91
PORTREVISION=	1
CATEGORIES=	audio devel
MASTER_SITES=	http://www.hawksoft.com/download/files/
DISTNAME=	HawkVoiceDI091src

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Portable sound and speech compression library

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
USES=		gmake dos2unix zip
MAKEFILE=	makefile.linux
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_ARGS=	LIBDIR=${STAGEDIR}${PREFIX}/lib \
		INCDIR=${STAGEDIR}${PREFIX}/include

WRKSRC=	${WRKDIR}/HawkVoiceDI/src

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS

CFLAGS_amd64=	-fPIC -DPIC
CFLAGS_ia64=	-fPIC -DPIC

OPTIMIZED_CFLAGS_CFLAGS=	-funroll-all-loops -ffast-math -fomit-frame-pointer -D_GNU_SOURCE -D_REENTRANT

post-patch:
	@${FIND} ${WRKSRC} -type f -exec ${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' "{}" \;

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libHVDI.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in api.txt HVDIchanges.txt readme.txt cryptapi.txt
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
