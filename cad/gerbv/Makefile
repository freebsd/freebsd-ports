# ex:ts=8
# Ports collection makefile for:	gerbv
# Date created:			Jul 16, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gerbv
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Free Gerber Viewer

USE_GNOME=	gdkpixbuf gnometarget
USE_REINPLACE=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-exportpng

MAN1=	gerbv.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e "s|malloc.h|stdlib.h|g" ${WRKSRC}/src/amacro.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
