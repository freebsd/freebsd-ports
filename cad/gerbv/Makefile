# ex:ts=8
# Ports collection makefile for:	gerbv
# Date created:			Jul 16, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gerbv
PORTVERSION=	2.0.0
CATEGORIES=	cad
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Free Gerber Viewer

USE_GNOME=	gnometarget gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		gerbv.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${FIND} ${WRKSRC} -name "configure" | ${XARGS} ${REINPLACE_CMD} -e \
		's|LIBPNG_CONFIG --cflags|PKG_CONFIG --cflags libpng12|g ; \
		 s|LIBPNG_CONFIG --ldflags|PKG_CONFIG --libs libpng12|g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.fig ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/PNG-print
	${INSTALL_DATA} ${WRKSRC}/doc/PNG-print/*.jpg ${DOCSDIR}/PNG-print
	${INSTALL_DATA} ${WRKSRC}/doc/PNG-print/*.txt ${DOCSDIR}/PNG-print
	@${MKDIR} ${DOCSDIR}/eagle
	${INSTALL_DATA} ${WRKSRC}/doc/eagle/*.pl ${DOCSDIR}/eagle
	${INSTALL_DATA} ${WRKSRC}/doc/eagle/*.txt ${DOCSDIR}/eagle
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${FIND} . ! -name "*Makefile*" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
