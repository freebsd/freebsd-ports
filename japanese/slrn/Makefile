# Created by: Takashi Mega <mega@minz.org>
# $FreeBSD$

PORTNAME=	slrn
PORTVERSION=	0.9.6.2
CATEGORIES=	japanese news
MASTER_SITES=	http://dists.lovepeers.org/distfiles/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-doc-j0.9.5.6-0.tar.gz

PATCH_SITES=	${MASTER_SITE_PORTS_JP} \
		http://dists.lovepeers.org/distfiles/
PATCHFILES=	${PORTNAME}-${PORTVERSION}jp0.pat.gz
PATCH_DIST_STRIP=-p1

MAINTAINER=	koma2@lovepeers.org
COMMENT=	Newsreader based on the S-Lang library

LICENSE=	GPLv2

LIB_DEPENDS=	slang:${PORTSDIR}/japanese/libslang

CONFLICTS=	slrn-0.*

GNU_CONFIGURE=	yes
ALL_TARGET=	all slrnpull
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
JDOCSRC=	${WRKDIR}/${PORTNAME}-doc-j0.9.5.6-0

MANLANG=	'' ja
MAN1=		slrn.1

# Tentatively improve inner makefiles in attempt to fix parallel builds
post-patch:
	@${REINPLACE_CMD} -e 's|-mkdir|mkdir -p| ; \
		/DOT_O_DEPS/s|$$| $$(OBJDIR)|' \
			${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -E 's|cd (.+); (\$$\(MAKE\))|\2 -C \1|' \
		${WRKSRC}/autoconf/Makefile.in

post-install:
	${INSTALL_MAN} ${JDOCSRC}/slrn.1 ${MANPREFIX}/man/ja/man1
	${CP} -a ${JDOCSRC} ${PREFIX}/share/doc/slrn/ja

.include <bsd.port.mk>
