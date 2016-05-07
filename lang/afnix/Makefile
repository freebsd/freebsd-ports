# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	afnix
PORTVERSION=	2.6.2
CATEGORIES=	lang
MASTER_SITES=	http://www.afnix.org/ftp/ \
		ftp://ftp.stack.nl/pub/users/johans/afnix/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Multi-threaded functional programming language

BROKEN_powerpc=		does not configure
BROKEN_powerpc64=	Does not build

USES=		compiler:c++11-lang gmake tar:tgz
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	cnf/bin/afnix-setup
CONFIGURE_ARGS=		-o --prefix "${PREFIX}" --altdir "${PREFIX}" \
			--shrdir "${PREFIX}/share" --compiler clang++

PORTDOCS=	*
PLIST_SUB=	PORTVER=${PORTVERSION:R}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|$$(CP)|$$(BSD_INSTALL_PROGRAM)|' \
		${WRKSRC}/src/*/*/exe/Makefile
	@${REINPLACE_CMD} -e '/\.rtf/d' ${WRKSRC}/etc/Makefile
	@${REINPLACE_CMD} -e '/uname -r/s/\\\./[.-]/' \
		${WRKSRC}/cnf/bin/afnix-guess

post-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} doc
	@cd ${WRKSRC}/prj && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} doc

post-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} DESTDIR=${STAGEDIR} ${MAKE_CMD} publish

.include <bsd.port.mk>
