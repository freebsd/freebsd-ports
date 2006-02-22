# New ports collection makefile for:	denemo
# Date created:				2001-02-24
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	denemo
PORTVERSION=	0.7.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical score editor

USE_X_PREFIX=	yes
USE_GNOME=	gnometarget gtk20 libxml2
USE_BISON=	yes
USE_GETTEXT=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|CXXFLAGS="$$CFLAGS|CXXFLAGS="$$DENEMO_CFLAGS|g' \
		-e 's|-Wall -O2|-Wall $$CXXFLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|denemo/denemo|denemo|g" ${WRKSRC}/src/kbd-custom.cpp
	@${REINPLACE_CMD} -e "s|^setkey|dsetkey|g" ${WRKSRC}/src/lyparserfuncs.cpp
	@${REINPLACE_CMD} -e "s| setkey| dsetkey|g" ${WRKSRC}/src/lyparserfuncs.h
	@${REINPLACE_CMD} -e "s|malloc.h|stdlib.h|g" ${WRKSRC}/m4/gettext.m4 \
		${WRKSRC}/ltmain.sh ${WRKSRC}/src/file.cpp ${WRKSRC}/src/lyparser.cpp \
		${WRKSRC}/src/lyparser.y

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in AUTHORS ChangeLog DESIGN GOALS NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
