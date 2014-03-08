# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	opendis
PORTVERSION=	0.0.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/ods/ods/${PORTVERSION} \
		http://ods.sourceforge.net/dl/


MAINTAINER=	ports@FreeBSD.org
COMMENT=	Access Flashpoint Digita-based cameras, download images, and more

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
GNU_CONFIGURE=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-pedantic -W|-pedantic|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| -g| @CFLAGS@|g' ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in NEWS AUTHORS doc/ERRATA doc/PHILOSOPHY doc/THUMB
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
