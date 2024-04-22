PORTNAME=	runawk
DISTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper for AWK interpreter that implements a modules system
WWW=		https://sourceforge.net/projects/runawk/

LICENSE=	MIT

BUILD_DEPENDS=	mk-configure>=0.26.0:devel/mk-configure

USES=		localbase

MAKE_ENV=	DESTDIR="${STAGEDIR}" EGDIR="${EXAMPLESDIR}" MANDIR="${PREFIX}/share/man"
INSTALL_TARGET=	install

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_INSTALL_TARGET=	install-doc
EXAMPLES_INSTALL_TARGET=install-examples

do-build:
	@${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mkcmake -C ${WRKSRC}

do-install:
	@${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mkcmake -C ${WRKSRC} ${INSTALL_TARGET}

.include <bsd.port.mk>
