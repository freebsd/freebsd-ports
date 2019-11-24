# Created by: Gerrit Beine (<tux@pinguru.net>)
# $FreeBSD$

PORTNAME=	gseen.mod
PORTVERSION=	1.1.1.p3
PORTREVISION=	5
CATEGORIES=	irc
MASTER_SITES=	http://www.kreativrauschen.de/gseen.mod/
DISTNAME=	${PORTNAME}.${PORTVERSION:S/p/dev/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Seen-module for the eggdrop IRC bot

LICENSE=	GPLv2+

EXTRACT_DEPENDS=${NONEXISTENT}:irc/eggdrop16:extract
BUILD_DEPENDS=	eggdrop:irc/eggdrop16
RUN_DEPENDS=	eggdrop:irc/eggdrop16

USES=		tcl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcllib=${LOCALBASE}/lib/libtcl${TCL_VER:S/.//}.so \
		--with-tclinc=${TCL_INCLUDEDIR}/tcl.h
WRKSRC=		${WRKDIR}/eggdrop
LLD_UNSAFE=	yes
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

do-extract:
	@${RM} -r ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} -R $$(${MAKE} -C ${PORTSDIR}/irc/eggdrop16 -V WRKSRC) ${WRKSRC}
	cd ${WRKSRC}/src/mod && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${EXTRACT_ONLY} ${EXTRACT_AFTER_ARGS}

post-extract:
	@${REINPLACE_CMD} -e 's|"-g -O2"|"${CFLAGS}"|' \
		-e 's|"-g"|"${CFLAGS}"|' \
		-e 's|"-O2"|"${CFLAGS}"|' \
		${WRKSRC}/configure

pre-configure:
	@${ECHO_CMD} gseen.mod >> ${WRKSRC}/.modules
	@${ECHO_CMD} gseen.mod >> ${WRKSRC}/.known_modules

do-install:
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/lib/eggdrop \
	    ${STAGEDIR}${LOCALBASE}/share/eggdrop/language
	${INSTALL_PROGRAM} ${WRKSRC}/gseen.so \
	    ${STAGEDIR}${LOCALBASE}/lib/eggdrop
	${INSTALL_DATA} ${WRKSRC}/src/mod/gseen.mod/*lang \
	    ${STAGEDIR}${LOCALBASE}/share/eggdrop/language
	${INSTALL_DATA} ${WRKSRC}/src/mod/gseen.mod/gseen.conf \
	    ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
