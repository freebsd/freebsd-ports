# $FreeBSD$

PORTNAME=	hoichess
PORTVERSION=	0.12.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.hoicher.de/hoichess/download/ \
		ftp://ftp.stack.nl/pub/users/johans/hoichess/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Not-so-very-strong chess engine

BROKEN=		unfetchable

USES=		gmake perl5 readline
USE_PERL5=	build
MAKE_JOBS_UNSAFE=yes
MAKE_ENV=	HAVE_GETOPT=1

OPTIONS_DEFINE=	DOCS

post-patch:
	@${RM} ${WRKSRC}/src/lib/getopt.h
	@${REINPLACE_CMD} -e '1,/^LDFLAG/d' ${WRKSRC}/src/Makefile.config
	@${ECHO_CMD} 'INSTALL = ${INSTALL}' >>  ${WRKSRC}/src/Makefile.config
	@${ECHO_CMD} 'CXXFLAGS += $${CPPFLAGS}' >> ${WRKSRC}/src/Makefile.config
	@${REINPLACE_CMD} -Ee '/INSTALL|install/s/ -D / /' \
		${WRKSRC}/src/Makefile ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '1,/^####/d' ${WRKSRC}/src/Makefile
	@${ECHO_CMD} 'LIBPATH = ${LDFLAGS}' >> ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e '/^prefix/s|= .*|= ${STAGEDIR}$${PREFIX}|' \
		-e '/bindir/s/games/bin/; /mandir/s/share//' ${WRKSRC}/Makefile

.include <bsd.port.mk>
