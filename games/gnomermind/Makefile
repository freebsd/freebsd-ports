# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnomermind
PORTVERSION=	1.0.1
PORTREVISION=	10
CATEGORIES=	games gnome
MASTER_SITES=	SF/${PORTNAME}/GnomerMind/${PORTVERSION}%20_Dreaming%20clovers_

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A puzzle game for Gnome, loosely based on the classic MasterMind game

USE_BZIP2=	yes
USES=        pathfix
USE_GNOME=	gdkpixbuf gnomelibs gnomeprefix
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	OLD_PO_FILE_INPUT=1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|^Info|#Info|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog HACKING NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
