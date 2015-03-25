# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	afnix
PORTVERSION=	2.5.1
CATEGORIES=	lang
MASTER_SITES=	http://www.afnix.org/ftp/ \
		ftp://ftp.stack.nl/pub/users/johans/afnix/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Multi-threaded functional programming language

USES=		gmake tar:tgz
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	cnf/bin/afnix-setup
CONFIGURE_ARGS=		-o --prefix "${PREFIX}" --altdir "${PREFIX}" \
			--shrdir "${PREFIX}/share" --compiler clang++

PORTDOCS=	*
PLIST_SUB=	PORTVER=${PORTVERSION:R}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not configure on powerpc
.endif

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
.if ! ${PORT_OPTIONS:MDOCS}
. for i in ${MAN1} ${MAN3} ${MAN7}
	${INSTALL_MAN} ${WRKSRC}/bld/${PORTNAME}-doc-${PORTVERSION}/man/$i \
		${STAGEDIR}${MANPREFIX}/man/man${i:E}/
. endfor
.else
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} DESTDIR=${STAGEDIR} ${MAKE_CMD} publish
.endif

.include <bsd.port.post.mk>
