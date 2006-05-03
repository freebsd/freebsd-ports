# ex:ts=8
# New ports collection makefile for:   Maaate
# Date created:                Fab 12, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Maaate
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.cmis.csiro.au/maaate/packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MPEG audio analysis toolkit

USE_GMAKE=	yes
GNU_CONFIGURE=  yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g ; \
		 s|(CCLD|(CXXLD|g' ${WRKSRC}/demos/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in API.html ChangeLog THANKS applications.html
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
