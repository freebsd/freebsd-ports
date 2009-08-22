# New ports collection makefile for:	opmixer
# Date created:				2000-12-29
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	opmixer
PORTVERSION=	0.75
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/optronic/opMixer/${PORTVERSION}
DISTNAME=	opMixer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adjusts a mixer

LIB_DEPENDS=	gtkmm-1.2.2:${PORTSDIR}/x11-toolkits/gtkmm12

USE_BZIP2=	yes
USE_GNOME=	gtk12 gnometarget
GNU_CONFIGURE=	yes

PORTDOCS=	README
PLIST_FILES=	${BIN_PROGRAMS:S/^/bin\//}

BIN_PROGRAMS=	opmixer opmixer-load volset

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e  \
		's|(VScale \*)|VScale *|g ; \
		 s|(Adjustment \*)|Adjustment *|g ; \
		 s|(CheckButton \*)|CheckButton *|g' ${WRKSRC}/src/gui.cc
	@${REINPLACE_CMD} -e  \
		's|<string\.h>|<cstring>|g ; \
		 s|<iostream\.h>|<iostream>|g ; \
		 s|(LineInfo \*)|LineInfo *|g ; \
		 s| cout| std::cout|g ; \
		 s| endl| std::endl|g' ${WRKSRC}/src/ossmixer.cc
	@${REINPLACE_CMD} -e  \
		's|<stdlib\.h>|<cstdlib>|g ; \
		 s|<stdio\.h>|<cstdio>|g' ${WRKSRC}/src/ossmixer.hh
	@${REINPLACE_CMD} -e  \
		's| endl| std::endl|g' ${WRKSRC}/src/volset.cc

do-install:
.for file in ${BIN_PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
