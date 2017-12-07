# Created by: rene@FreeBSD.org
# $FreeBSD$

PORTNAME=	owl-lisp
PORTVERSION=	0.1.14
DISTVERSIONPREFIX=	v
CATEGORIES=	lang

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Functional dialect of Scheme

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USE_GITHUB=	yes
GH_ACCOUNT=	aoh

PLIST_FILES=	bin/ol \
		bin/ovm \
		man/man1/ol.1.gz \
		man/man1/ovm.1.gz \
		share/owl-lisp/fasl/init.fasl

MAKE_ENV+=	MANDIR=/man

# Do not strip the binaries because that will rebuild them during stage.
post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/fasl
	${INSTALL_DATA} ${WRKSRC}/fasl/init.fasl ${STAGEDIR}${DATADIR}/fasl/init.fasl

.include <bsd.port.mk>
