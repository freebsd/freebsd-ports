PORTNAME=	slrn
PORTVERSION=	0.9.6.2
PORTREVISION=	1
CATEGORIES=	japanese news
MASTER_SITES=	http://dists.lovepeers.org/distfiles/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-doc-j0.9.5.6-0.tar.gz

PATCH_SITES=	PORTS_JP \
		http://dists.lovepeers.org/distfiles/
PATCHFILES=	${PORTNAME}-${PORTVERSION}jp0.pat.gz
PATCH_DIST_STRIP=-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Newsreader based on the S-Lang library
WWW=		https://www.slrn.org/

LICENSE=	GPLv2

LIB_DEPENDS=	libslang.so:japanese/libslang

CONFLICTS=	slrn-0.*

GNU_CONFIGURE=	yes
ALL_TARGET=	all slrnpull
JDOCSRC=	${WRKDIR}/${PORTNAME}-doc-j0.9.5.6-0
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

MAKE_JOBS_UNSAFE=	yes

# Tentatively improve inner makefiles in attempt to fix parallel builds
post-patch:
	@${REINPLACE_CMD} -e 's|-mkdir|mkdir -p| ; \
		/DOT_O_DEPS/s|$$| $$(OBJDIR)|' \
			${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -E 's|cd (.+); (\$$\(MAKE\))|\2 -C \1|' \
		${WRKSRC}/autoconf/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/ja/man1
	${INSTALL_MAN} ${JDOCSRC}/slrn.1 \
		${STAGEDIR}${PREFIX}/share/man/ja/man1
	${CP} -a ${JDOCSRC} ${STAGEDIR}${PREFIX}/share/doc/slrn/ja

.include <bsd.port.mk>
