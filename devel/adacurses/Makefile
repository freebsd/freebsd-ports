# Created by: olgeni@FreeBSD.org
# $FreeBSD$

PORTNAME=	adacurses
PORTVERSION=	20110404
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/AdaCurses/
DISTNAME=	AdaCurses-${PORTVERSION}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Ada95 bindings for ncurses

LICENSE=	MIT

USES=		ada gmake tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ada-include=${PREFIX}/include/adacurses \
		--with-ada-objects=${PREFIX}/lib/adacurses \
		--libdir=${PREFIX}/lib/adacurses \
		--enable-widec

OPTIONS_DEFINE=	DOCS

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSREL:R} == 11
# PR 199109  The base ncurses has suffered a regression which prevents
# adacurses from building on -CURRENT.  The PR is not getting any attention
# and I'm sick of never-ending fallout messages so bring back ports ncurses
# for the FreeBSD 11 users.
USES+=	ncurses:port
.else
USES+=	ncurses
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|#if A|#ifdef A|g' ${WRKSRC}/gen/gen.c
	@${REINPLACE_CMD} -e '/(INSTALL_PROG)/d' ${WRKSRC}/gen/Makefile.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gen/adacurses-config \
		${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat
	${SED} "s|@PREFIX@|${PREFIX}|g" ${FILESDIR}/adacurses.gpr.in > \
		${STAGEDIR}${PREFIX}/lib/gnat/adacurses.gpr
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} install.html)
.else
	${RM} ${STAGEDIR}${PREFIX}/man/man1/adacurses-config.1
.endif

.include <bsd.port.mk>
