# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	afnix
PORTVERSION=	2.6.3
PORTREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	http://www.afnix.org/ftp/ \
		ftp://ftp.stack.nl/pub/users/johans/afnix/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-threaded functional programming language

BROKEN=		unfetchable

BROKEN_armv6=		fails to compile: operator new takes type size_t as first parameter
BROKEN_armv7=		fails to compile: operator new takes type size_t as first parameter
BROKEN_i386=		fails to build
BROKEN_powerpc=		fails to configure
BROKEN_powerpc64=	fails to build: afnix-setup: cannot determine linking type

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
