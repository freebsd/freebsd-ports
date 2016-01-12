# Created by: Nils M Holm <nmh@t3x.org>
# $FreeBSD$

PORTNAME=	s9fes
PORTVERSION=	20121005
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.t3x.org/s9fes/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable Scheme interpreter with a Unix interface

BROKEN=		unfetchable

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIBDIR=		${DATADIR}
MAKE_ARGS=	${MAKE_ENV}
WRKSRC=		${WRKDIR}/s9

post-patch:
	${REINPLACE_CMD} -E \
		-e 's|\$$\(BINDIR\)|$$(DESTDIR)$$(BINDIR)|g' \
		-e '/-DDEF|>s9.1.gz/!s|\$$\(LIBDIR\)|$$(DESTDIR)$$(LIBDIR)|g' \
		-e 's|\$$\(MANDIR\)|$$(DESTDIR)$$(MANDIR)|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
